#include <iostream>

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"
/* Qui utilizzeremo due costruttori per un singolo oggetto.
 * l'idea alla base è che l'oggetto è cosi complicato da richiedere
 * costruttori separati per ogni aspetto di quell'oggetto.
 */

int main()
{
    Person p = Person::create()
    .lives().at("123 London Road")
            .with_postcode("SW1 1GB")
            .in("London")
    .works().at("PragmaSoft")
            .as_a("Consultant")
            .earning(10e6);
    std::cout << p << std::endl;

    return 0;
}
