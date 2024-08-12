#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    const int LIMIT = 800;
    sf::Vector2f rectangleSize(70,100);
    sf::RectangleShape rectangle(rectangleSize);

    rectangle.setFillColor(sf::Color(100, 250, 50));

    rectangle.setOrigin(sf::Vector2f(-400, -500));

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1600, 1000), "Particle Accelerator");

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.scancode == sf::Keyboard::Scan::Space)
                    if (rectangleSize.x <= LIMIT)
                    {
                        rectangleSize.x += 10;
                        rectangle.setSize(rectangleSize);
                    }
            }
        }

        window->draw(rectangle);
        window->display();
    }

    return 0;
}
