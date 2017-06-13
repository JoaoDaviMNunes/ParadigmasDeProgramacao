# boost::bimap

## Introdução
<p>
Boost::bimap é uma biblioteca de mapas bidirecionais para C++. Com ela, você pode criar containers associados na qual os dois tipos podem ser usados como chave.<br>
Bimap<X,Y> é uma combinação de std::map<X,Y> e std::map<Y,X>.<br>
A curva de aprendizado do bimap é quase plana se sabe como usar os containers padrões.<br>
A classe foi feita para usar com os container STL comuns.<br>
</p>

[História da classe boost::bimap](http://www.boost.org/doc/libs/1_64_0/libs/bimap/doc/html/boost_bimap/history.html)

## Código exemplo
```
#include <iostream>
#include <boost/bimap.hpp>

struct country  {};
struct place    {};

int main()
{
    using namespace boost::bimaps;

    // Soccer World cup.

    typedef bimap
    <
        tagged< std::string, country >,
        tagged< int        , place   >

    > results_bimap;

    typedef results_bimap::value_type position;

    results_bimap results;
    results.insert( position("Argentina"    ,1) );
    results.insert( position("Spain"        ,2) );
    results.insert( position("Germany"      ,3) );
    results.insert( position("France"       ,4) );

    std::cout << "Countries names ordered by their final position:"
                << std::endl;

    1for( results_bimap::map_by<place>::const_iterator
            i    = results.by<place>().begin(),
            iend = results.by<place>().end() ;
            i != iend; ++i )
    {
        2std::cout << i->get<place  >() << ") "
                  << i->get<country>() << std::endl;
    }

    std::cout << std::endl
              << "Countries names ordered alfabetically along with"
                 "their final position:"
              << std::endl;

    3for( results_bimap::map_by<country>::const_iterator
            i    = results.by<country>().begin(),
            iend = results.by<country>().end() ;
            i != iend; ++i )
    {
        std::cout << i->get<country>() << " ends "
                  << i->get<place  >() << "º"
                  << std::endl;
    }

    return 0;
}
```

## Matias Capeletto
<p>
Desenvolvedor da classe bimap no contexto do Google SoC 2006.<br>
Dentre vários programadores que também estavam produzindo, Matias foi o que conseguiu apresentar uma melhor ideia e código para a classe. <br>
</p>

Sites:<br>
- [StackOverflow](https://stackoverflow.com/users/1191859/matias-capeletto)<br>
- [LinkedIn](https://br.linkedin.com/in/matiascapeletto)<br>

## Referências
- [Boost.org](http://www.boost.org/doc/libs/1_64_0/libs/bimap/doc/html/index.html)<br>
