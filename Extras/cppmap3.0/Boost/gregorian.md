# boost::gregorian

## Introdução

<p>
A classe dispõe de uma programação de data baseado no Calendário gregoriano (o nosso calendário), que foi introduzido no ano de 1582 para corrigir um erro no Calendário Juliano. Entretanto, muitos locais não adotaram a mudança, fazendo que datas históricas fiquem confusas.<br>
A classe possui funções que calcula dados através do calendário gregoriano, usando também o horário como informação adicional.<br>
</p>

## Código exemplo
```
/* Short example that calculates the number of days since user was born.
 * Demonstrates comparisons of durations, use of the day_clock,
 * and parsing a date from a string.
 */

#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>

int
main() 
{
  
  using namespace boost::gregorian;
  std::string s;
  std::cout << "Enter birth day YYYY-MM-DD (eg: 2002-02-01): ";
  std::cin >> s;
  try {
    date birthday(from_simple_string(s));
    date today = day_clock::local_day();
    days days_alive = today - birthday;
    days one_day(1);
    if (days_alive == one_day) {
      std::cout << "Born yesterday, very funny" << std::endl;
    }
    else if (days_alive < days(0)) {
      std::cout << "Not born yet, hmm: " << days_alive.days() 
                << " days" <<std::endl;
    }
    else {
      std::cout << "Days alive: " << days_alive.days() << std::endl;
    }

  }
  catch(...) {
    std::cout << "Bad date entered: " << s << std::endl;
  }
  return 0;
}
```

## Referências
- [Boost.org](http://www.boost.org/doc/libs/1_39_0/doc/html/date_time/gregorian.html)<br>
