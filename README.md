# Linguagem UNIT

Uma linguagem de programação com sistema de verificação de unidades físicas, inspirada em C.

## Visão Geral

A linguagem UNIT foi desenvolvida para demonstrar a verificação automática de compatibilidade de unidades físicas em expressões aritméticas. Esta funcionalidade é especialmente útil em aplicações científicas e de engenharia, onde erros de unidades podem levar a resultados incorretos ou catastróficos.

## Características Principais

### Sintaxe Familiar
- **Baseada em C**: A sintaxe é similar ao C, facilitando a adoção por programadores já familiarizados com a linguagem
- **Tipos básicos**: `int` e `float`
- **Estruturas de controle**: `for`, `if/else`
- **Comentários**: Suporte a comentários de linha (`//`) e de bloco (`/* */`)

### Sistema de Unidades Físicas

A linguagem suporta as seguintes unidades:

- **meters** - metros (distância/comprimento)
- **seconds** - segundos (tempo)
- **m_per_s** - metros por segundo (velocidade)
- **square_meter** - metros quadrados (área)

### Declaração de Variáveis com Unidades

```c
// Variáveis sem unidade (adimensionais)
float valor;
int contador = 5;

// Variáveis com unidades específicas
float:meters distancia = 100.0;
float:seconds tempo = 10.0;
float:m_per_s velocidade;
int:meters altura = 50;
```

### Verificação Automática de Compatibilidade

O compilador verifica automaticamente a compatibilidade de unidades em:

#### Operações Aritméticas
- **Soma/Subtração**: Apenas unidades iguais
- **Multiplicação**: Pode resultar em novas unidades (ex: meters * meters = square_meter)
- **Divisão**: Pode derivar unidades (ex: meters / seconds = m_per_s)

#### Exemplos Válidos:
```c
// Operações válidas
velocidade = distancia / tempo;    // meters / seconds = m_per_s
distancia = velocidade * tempo;    // m_per_s * seconds = meters
distancia = distancia + altura;    // meters + meters = meters
valor = altura / distancia;        // meters / meters = adimensional

// Operações com adimensionais
distancia = distancia * 2;         // meters * adimensional = meters
```

#### Exemplos que Geram Erro:
```c
// ERRO: Soma de unidades incompatíveis
float:meters resultado = distancia + tempo;  // meters + seconds

// ERRO: Atribuição incompatível
distancia = tempo;  // meters = seconds

// ERRO: Comparação de unidades diferentes
if (distancia < tempo) { ... }  // meters < seconds
```

### Estruturas de Controle

```c
// Loop FOR
for (int i = 0; i < contador; i = i + 1) {
    distancia = distancia + 10;
    printf("Loop: " i);
}

// Condicional IF/ELSE
if (velocidade < 20) {
    printf("Velocidade baixa");
    velocidade = velocidade + 5;
} else {
    printf("Velocidade alta");
}
```

### Entrada e Saída

```c
// Impressão de strings literais
printf("Teste finalizado");

// Impressão de variáveis
printf(contador);

// Impressão combinada (string + variável)
printf("Contador: " contador);
```

## Regras de Conversão de Unidades

O sistema implementa as seguintes regras de conversão:

| Operação | Resultado | Exemplo |
|----------|-----------|---------|
| meters ÷ seconds | m_per_s | distancia / tempo |
| meters ÷ m_per_s | seconds | distancia / velocidade |
| m_per_s × seconds | meters | velocidade * tempo |
| meters × meters | square_meter | comprimento * largura |
| meters ÷ meters | adimensional | altura / distancia |
| qualquer_unidade × adimensional | qualquer_unidade | distancia * 2 |
| qualquer_unidade ÷ adimensional | qualquer_unidade | velocidade / 2.0 |

## Compilação e Execução

O projeto utiliza Flex (lexer) e Bison (parser):

```bash
# Compilar o projeto
make

# Executar com arquivos de teste aceitos
./cmp teste-aceito-1.txt
./cmp teste-aceito-2.txt
./cmp teste-aceito-3.txt

# Testar casos com erros
./cmp teste-erro-semantico-1.txt
./cmp teste-erro-semantico-2.txt
./cmp teste-erro-semantico-3.txt
```

## Arquivos do Projeto

- **unit.l**: Analisador léxico (Flex)
- **unit.y**: Analisador sintático e semântico (Bison)
- **nodes.h**: Definição das classes da AST e Análise Semântica
- **teste-aceito-1.txt**: Exemplo básico com declarações e operações simples
- **teste-aceito-2.txt**: Estruturas de controle (for, if/else)
- **teste-aceito-3.txt**: Conversões complexas e I/O
- **teste-erro-semantico-*.txt**: Testes de erros semânticos
- **teste-erro-sintatico-*.txt**: Testes de erros sintáticos
- **makefile**: Script de compilação

## Limitações Atuais

- Conjunto limitado de unidades físicas
- Verificação de tipos realizada durante a análise sintática (idealmente seria na análise semântica)
- Não suporte a arrays ou estruturas
- Sistema de I/O simplificado

## Objetivos Educacionais

Esta linguagem foi desenvolvida para demonstrar:

1. **Implementação de análise léxica e sintática**
2. **Sistema de tipos customizado**
3. **Verificação semântica de compatibilidade**
4. **Integração Flex + Bison**
5. **Aplicação prática de conceitos de compiladores**

## Exemplo Completo

```c
/*
 * Programa exemplo em UNIT
 */

// Declarações
float:meters distancia = 100.0;
float:seconds tempo = 10.0;
float:m_per_s velocidade;
int contador = 0;

// Cálculos físicos
velocidade = distancia / tempo;      // 100m / 10s = 10 m/s
distancia = velocidade * tempo;      // 10 m/s * 10s = 100m

// Estrutura de controle
for (int i = 0; i < 5; i = i + 1) {
    if (velocidade > 8) {
        printf("Velocidade alta");
        velocidade = velocidade - 1;
    } else {
        printf("Velocidade baixa");
    }
    contador = contador + 1;
}

printf("Simulacao finalizada");
```

## Tratamento de Erros

O compilador fornece relatórios detalhados de erros:

```bash
# Exemplo de saída com erros
ERRO na linha 16: ERRO DE UNIDADE: Atribuicao de unidade incompativel.
ERRO na linha 23: ERRO DE UNIDADE: Multiplicacao de unidades sem regra definida.
Total de erros encontrados: 2
```

O sistema detecta:
- **Erros de unidade**: Incompatibilidade entre unidades físicas
- **Erros de sintaxe**: Problemas na estrutura do código
- **Erros semânticos**: Variáveis não declaradas, etc.
