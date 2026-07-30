*Este projeto foi criado como parte do currículo 42 por audgiova.*

## Descrição

A **libft** é uma biblioteca C que reimplementa as funções mais comuns da libc (biblioteca padrão do C). O objetivo é entender profundamente como essas funções funcionam internamente e dominar conceitos fundamentais de programação em C.

Este projeto faz parte do currículo da 42 e serve como base para todos os projetos futuros da escola, sendo reutilizada em diversos contextos durante o programa de estudos.

### Objetivo do Projeto

- Implementar as funções essenciais da libc do zero
- Aprofundar o conhecimento em manipulação de memória
- Compreender estruturas de dados e algoritmos básicos
- Estabelecer boas práticas de programação em C
- Criar uma biblioteca reutilizável para projetos futuros

## Descrição Detalhada da Biblioteca

A libft é composta por dois conjuntos principais de funções:

### 1. Funções Parte Obrigatória

Reimplementações de funções padrão da libc:

#### Funções de Classificação de Caracteres
- `ft_isalpha()` - Verifica se é uma letra (A-Z, a-z)
- `ft_isdigit()` - Verifica se é um dígito (0-9)
- `ft_isalnum()` - Verifica se é alfanumérico
- `ft_isascii()` - Verifica se está na tabela ASCII
- `ft_isprint()` - Verifica se é imprimível

#### Funções de Conversão
- `ft_toupper()` - Converte para maiúscula
- `ft_tolower()` - Converte para minúscula
- `ft_atoi()` - Converte string para inteiro
- `ft_itoa()` - Converte inteiro para string

#### Funções de Manipulação de Memória
- `ft_memset()` - Preenche memória com um valor
- `ft_bzero()` - Limpa (zera) uma área de memória
- `ft_memcpy()` - Copia memória (áreas não sobrepostas)
- `ft_memmove()` - Copia memória (áreas podem se sobrepor)
- `ft_memchr()` - Busca um byte na memória
- `ft_memcmp()` - Compara áreas de memória
- `ft_calloc()` - Aloca memória inicializada com zero

#### Funções de Manipulação de Strings
- `ft_strlen()` - Retorna o tamanho da string
- `ft_strchr()` - Busca um caractere na string (primeira ocorrência)
- `ft_strrchr()` - Busca um caractere na string (última ocorrência)
- `ft_strncmp()` - Compara n caracteres de duas strings
- `ft_strnstr()` - Busca uma substring dentro de n caracteres
- `ft_strlcpy()` - Copia string com limite de tamanho (segura)
- `ft_strlcat()` - Concatena string com limite de tamanho (segura)
- `ft_strdup()` - Duplica uma string
- `ft_strjoin()` - Concatena duas strings com alocação dinâmica
- `ft_strtrim()` - Remove caracteres de um conjunto das extremidades
- `ft_substr()` - Extrai uma substring
- `ft_split()` - Divide uma string por um delimitador
- `ft_strmapi()` - Aplica uma função a cada caractere (com índice)
- `ft_striteri()` - Itera sobre cada caractere aplicando uma função

#### Funções de Escrita
- `ft_putchar_fd()` - Escreve um caractere em um file descriptor
- `ft_putstr_fd()` - Escreve uma string em um file descriptor
- `ft_putendl_fd()` - Escreve uma string com quebra de linha
- `ft_putnbr_fd()` - Escreve um número em um file descriptor

### 2. Funções Parte Bônus - Manipulação de Listas Ligadas

Implementação de estrutura de dados e operações em lista ligada simples:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

```

* `ft_lstnew()` - Cria um novo nó
* `ft_lstadd_front()` - Adiciona um nó no início
* `ft_lstadd_back()` - Adiciona um nó no final
* `ft_lstsize()` - Retorna o tamanho da lista
* `ft_lstlast()` - Retorna o último nó
* `ft_lstiter()` - Itera sobre cada nó aplicando uma função
* `ft_lstmap()` - Cria uma nova lista aplicando uma função
* `ft_lstdelone()` - Deleta um nó
* `ft_lstclear()` - Deleta toda a lista

## Instruções de Compilação e Uso

### Pré-requisitos

* GCC ou Clang
* Make
* Linux/Unix

### Compilação

Para compilar a biblioteca:

```bash
make

```

Isso gera `libft.a` - a biblioteca estática.

Para compilar tudo e depois limpar os arquivos objeto:

```bash
make all

```

### Limpeza

Para remover os arquivos objeto:

```bash
make clean

```

Para remover tudo (objeto e biblioteca):

```bash
make fclean

```

Para limpar e recompilar:

```bash
make re

```

### Uso da Biblioteca

Para usar a libft em seu projeto:

1. Inclua o arquivo de cabeçalho:

```c
#include "libft.h"

```

2. Compile seu programa linkando a biblioteca:

```bash
gcc -o seu_programa seu_arquivo.c -L. -lft

```

Ou adicione ao seu Makefile:

```makefile
LIBS = -L. -lft
CFLAGS = -Wall -Wextra -Werror
gcc $(CFLAGS) -o programa main.c $(LIBS)

```

### Exemplo de Uso

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char    str[] = "Hello, World!";
    
    // Verificar características
    printf("Tamanho: %lu\n", ft_strlen(str));           // 13
    printf("Maiúscula: %c\n", ft_toupper('a'));         // A
    
    // Manipulação de string
    char *duplicada = ft_strdup(str);
    char *resultado = ft_strjoin("Prefix: ", str);
    
    free(duplicada);
    free(resultado);
    
    return 0;
}

```

---

**Versão**: 1.0
**Data**: Junho 2026
**Projeto**: 42 School - libft

## Recursos

### Referências Utilizadas

* [TutorialsPoint - memset](https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm)
* [GeeksforGeeks - size_t data type](https://www.geeksforgeeks.org/c/size_t-data-type-c-language/)
* [Stack Overflow PT - Importar funções de outro arquivo](https://pt.stackoverflow.com/questions/154070/como-importar-fun%C3%A7%C3%B5es-de-outro-arquivo-em-c)
* [YouTube - Vídeo de Referência](https://www.youtube.com/watch?v=1Hgl4TU8CB0)
* [TutorialsPoint - malloc](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm)
* [W3Schools - malloc reference](https://www.w3schools.com/c/ref_stdlib_malloc.php)
* [IME-USP - Alocação Dinâmica](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)
* [Stack Overflow - Funcionamento de loops if/while com variáveis](https://stackoverflow.com/questions/18094290/how-does-if-variable-whilevariable-work-in-c-programming)
* [Stack Overflow - Ponteiros de caracteres em loops while](https://stackoverflow.com/questions/36391599/understanding-character-pointers-in-a-while-loop)
* [Stack Overflow - Ponteiros de caracteres NULL em loops](https://stackoverflow.com/questions/68954500/working-with-character-pointers-null-in-while-loop)
* [GeeksforGeeks - Ponteiros de função](https://www.geeksforgeeks.org/c/function-pointer-in-c/)
* [Programiz - Ponteiros em C](https://www.programiz.com/c-programming/c-pointers)
* [GeeksforGeeks - Chamadas de sistema I/O](https://www.geeksforgeeks.org/dsa/insertion-in-linked-list/)
* [Man7.org - Manual da chamada write](https://man7.org/linux/man-pages/man2/write.2.html)
* [GeeksforGeeks - Inserção em listas ligadas](https://www.geeksforgeeks.org/dsa/insertion-in-linked-list/)
* [W3Schools - calloc reference](https://www.w3schools.com/c/ref_stdlib_calloc.php)
* [GeeksforGeeks - Listas ligadas em C](https://www.geeksforgeeks.org/c/linked-list-in-c/)
* [Learn-C.org - Introdução a Listas Ligadas](https://www.learn-c.org/en/Linked_lists)

### Uso de IA

A IA foi utilizada neste projeto para:
* **Pesquisa**: Levantamento de informações sobre as funções da libc baseado em documentações e referências
* **Montagem do README**: Estruturação e organização da documentação do projeto, incluindo descrições detalhadas das funções, exemplos de uso e instruções de compilação
