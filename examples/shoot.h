#ifndef SHOOT_H
#define SHOOT_H

using namespace Mgt;

int shoot() {
    const int larguraTela = 1024;
    const int alturaTela = 768;

    Point pontoInicial = {larguraTela / 2.f, alturaTela / 2.f};
    Point pontoFinal = {200.f, 200.f};
    auto v = pontoFinal - pontoInicial;
    float speed = magnitude(v);
    auto u = unit_length(v) * (speed / 100.f);
    Point pontoAtual = pontoInicial;
    show(larguraTela, alturaTela, BLACK, [&]() {
        Mgt::DrawVector(v, BLACK, pontoInicial);
        DrawCircle(pontoAtual.first, pontoAtual.second, 5.f, RED);
        int d = static_cast<int>(distance(pontoAtual, pontoFinal));
        if (d > 0) {
            std::cout << d
                      << " "
                      << pontoAtual
                      << " -> "
                      << pontoFinal
                      << '\n';
            auto& [px, py] = pontoAtual;
            px += u[0];
            py += u[1];
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            Vector2 mousePosition = GetMousePosition();
            pontoFinal = {mousePosition.x, mousePosition.y};
            pontoAtual = pontoInicial;
            v = pontoFinal - pontoAtual;
            speed = magnitude(v);
            u = unit_length(v) * speed / 10.f;
        }
    });
    return 0;
}

#endif // SHOOT_H
