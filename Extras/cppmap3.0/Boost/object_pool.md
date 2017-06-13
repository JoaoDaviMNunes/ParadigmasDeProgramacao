# boost::object_pool

## Introdução
<p>
Pode ser usado para uma alocação rápida e eficiente na memória para os objetos de tipo T.<br>
Provê também uma destruição automática dos elementos não-desalocados.<br>
A interface do template da classe object_pool é uma interface de uso de Objeto com retorno NULL, ciente do tipo de objeto que está alocando na memória. Nesta classe, não precisamos prover memória, ela aloca memória automaticamente.<br>
</p>

## Código exemplo:
```
template <typename ElementType, typename UserAllocator = default_user_allocator_new_delete>
class object_pool
{
  private:
    object_pool(const object_pool &);
    void operator=(const object_pool &);

  public:
    typedef ElementType element_type;
    typedef UserAllocator user_allocator;
    typedef typename pool<UserAllocator>::size_type size_type;
    typedef typename pool<UserAllocator>::difference_type difference_type;

    object_pool();
    ~object_pool();

    element_type * malloc();
    void free(element_type * p);
    bool is_from(element_type * p) const;

    element_type * construct();
    // other construct() functions
    void destroy(element_type * p);
};
```

## Referências:
- [Site 1](http://www.boost.org/doc/libs/1_42_0/libs/pool/doc/interfaces/object_pool.html)
- [Site 2](http://www.boost.org/doc/libs/1_64_0/libs/pool/doc/html/header/boost/pool/object_pool_hpp.html)
- [Site 3](http://www.boost.org/doc/libs/1_64_0/libs/pool/doc/html/boost_pool/pool/interfaces.html#boost_pool.pool.interfaces.interfaces.object_pool)
