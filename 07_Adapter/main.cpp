#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>

// Callback per gli errori di GLFW
static void glfw_error_callback(int error, const char* description) {
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;
}

int main() {
    // Inizializza GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        std::cerr << "Errore nell'inizializzazione di GLFW!" << std::endl;
        return -1;
    }

    // Configura GLFW per OpenGL 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    float display_w{1280.0};
    float display_h{720.0};

    // Crea la finestra
    GLFWwindow* window = glfwCreateWindow(display_w, display_h, "Graphics", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Errore nella creazione della finestra!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Abilita V-Sync

    // Setup ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Imposta lo stile
    ImGui::StyleColorsDark();

    // Inizializza i backend di ImGui
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    // Variabili per la demo
    bool show_demo_window = true;
    bool show_another_window = true;
    ImVec4 clear_color = ImVec4(0.10f, 0.1f, 0.1f, 1.00f);
    float counter_value = 0.0f;
    char text_buffer[256] = "Ciao dal buffer di testo!";

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Inizia il frame ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Finestra principale "Hello World"
        {

            ImGui::SetNextWindowSize(ImVec2(display_w, display_h)); // Dimensione intera
            ImGui::SetNextWindowPos(ImVec2(0, 0)); // Posizione nell'angolo in alto a sinistra

            // Usa il flag NoDecoration per rimuovere decorazioni
            ImGui::Begin("main", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);


            ImGui::Text("Benvenuto in ImGui!");

            if (ImGui::Button("Incrementa contatore"))
                counter_value++;

            ImGui::SameLine();
            ImGui::Text("Valore = %.1f", counter_value);

            ImGui::InputText("Testo", text_buffer, IM_ARRAYSIZE(text_buffer));

            ImGui::Checkbox("Mostra finestra demo", &show_demo_window);
            ImGui::Checkbox("Mostra altra finestra", &show_another_window);

            ImGui::SliderFloat("Valore float", &counter_value, 0.0f, 100.0f);
            ImGui::ColorEdit3("Colore di sfondo", (float*)&clear_color);

            ImGui::Text("Framerate medio: %.3f ms/frame (%.1f FPS)",
                       1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

            ImGui::End();
        }

        // Rendering
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w,
                     clear_color.y * clear_color.w,
                     clear_color.z * clear_color.w,
                     clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}