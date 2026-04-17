#ifndef VEC2_H
#define VEC2_H
class Vec2 {
    public:
        float x;
        float y;

        // ● Construtores com inicialização em valores dados e/ou em zero
        Vec2(float x = 0, float y = 0);
       
        // ● Soma/subtração de vetores
        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
       
        // ● Multiplicação de vetor por escalar
        Vec2 operator*(float scalar) const;
        
        // Magnitude
        //sqrt(x*x + y*y);
        float magnitude() const;
        
        // Cálculo do vetor normalizado
        Vec2 normalized() const;

        // ● Distância entre um ponto e outro
        float distance(const Vec2& other) const;

        /*
            ● Inclinação de um vetor em relação ao eixo x
            A inclinação de um vetor em relação ao eixo x é o ângulo θ que ele forma com a horizontal.
            Esse ângulo pode ser calculado usando a função arco tangente da razão entre as componentes
            vertical (y) e horizontal (x) do vetor:

                θ = arctan(y / x)  ou  θ = tan⁻¹(y / x)

            O valor de θ geralmente está no intervalo de -90° a 90° (ou -π/2 a π/2 em radianos),
            dependendo dos sinais das componentes do vetor.
        */
        float angle() const;

        /*
            ● Inclinação de um vetor em relação ao eixo x

            A inclinação de um vetor em relação ao eixo x é o ângulo θ formado entre o vetor
            e a direção horizontal. Esse ângulo indica a direção do vetor no plano cartesiano.

            Ele pode ser determinado pela razão entre a componente vertical (y) e a
            componente horizontal (x), utilizando a função arco tangente:

                θ = arctan(y / x)

            Esse ângulo descreve a orientação do vetor e pode variar conforme o quadrante
            em que ele se encontra.
        */
        float angleTo(const Vec2& other) const;

        /*
            ● Rotação em um determinado ângulo

            A rotação de um ponto (x, y) por um ângulo θ pode ser realizada
            utilizando matrizes de rotação. As novas coordenadas (x’, y’) são dadas por:

                x’ = x * cos(θ) - y * sin(θ)
                y’ = y * cos(θ) + x * sin(θ)

            Essas equações permitem rotacionar o ponto em torno da origem.

            Observação:
            Se o eixo y for considerado positivo para baixo (como em muitos sistemas
            gráficos de computador), então um ângulo positivo resulta em uma rotação
            no sentido horário.
        */
        Vec2 rotated(float angle) const;
        
};

#endif