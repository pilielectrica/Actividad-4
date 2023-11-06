#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
///Punto de entrada a la aplicación///
using namespace std;

Sprite cuadrado;
Sprite cursor;

Texture texturecuadrado;
Texture texturecirculo;
Texture texturecursor;
int main() {
	Event evt;

	texturecuadrado.loadFromFile("cuad_yellow.png");
	texturecirculo.loadFromFile("rcircleg.png");
	texturecursor.loadFromFile("cursor.png");

	cuadrado.setTexture(texturecuadrado);
	cursor.setTexture(texturecursor);

	cuadrado.setScale(0.3f, 0.3f);

    float cuadrado_height = (float)texturecuadrado.getSize().y;
	float cuadrado_width = (float)texturecuadrado.getSize().x;

	float height_circulo, width_circulo;

	height_circulo = (float)texturecirculo.getSize().y;
	width_circulo = (float)texturecirculo.getSize().x;


	float escalaYcirculo, escalaXcirculo;

	escalaYcirculo = cuadrado_height*0.3 / height_circulo;
	escalaXcirculo = cuadrado_width*0.3 / width_circulo;

	
	int posicion_imagenX = ((600 - cuadrado_width*0.3f) / 2);
	int posicion_imagenY = ((600 - cuadrado_height*0.3f) / 2);
	int posicion_circuloX = ((600 - width_circulo) / 2);
	int posicion_circuloY = ((600 - height_circulo) / 2);

	cuadrado.setPosition(posicion_imagenX, posicion_imagenY);
	
	
	cursor.setPosition(0, 0);
	cursor.setScale(0.1f, 0.1f);


	sf::RenderWindow App(sf::VideoMode(600, 600, 32),
		"Que ventana horrible");
	App.setMouseCursorVisible(false);

	// Loop principal
	while (App.isOpen()) {
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type) {
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::MouseMoved:
				/////Actualizamos la posición del sprite con/////
				/////la informacion del evento del mouse/////
				cursor.setPosition(evt.mouseMove.x, evt.mouseMove.y);

			case Event::KeyPressed:
				if ((Keyboard::isKeyPressed(Keyboard::Left) == true) && (posicion_imagenX >=0))
				{
					cuadrado.setPosition(posicion_imagenX--, posicion_imagenY);
					
				}				

				if ((Keyboard::isKeyPressed(Keyboard::Right) == true) && (posicion_imagenX <= (600-cuadrado_width*0.3f)))
				{
					cuadrado.setPosition(posicion_imagenX++, posicion_imagenY);
			
				}

				if ((Keyboard::isKeyPressed(Keyboard::Up) == true) && (posicion_imagenY >= 0))
				{
					cuadrado.setPosition(posicion_imagenX, posicion_imagenY--);
			
				}

				if ((Keyboard::isKeyPressed(Keyboard::Down) == true) && (posicion_imagenY <= (600 - cuadrado_height*0.3f)))
				{
					cuadrado.setPosition(posicion_imagenX, posicion_imagenY++);
					
				}			
			}
		}
		App.clear();	
		
		
		App.draw(cuadrado);
		if (evt.key.code == sf::Keyboard::Space)
		{
			cuadrado.setScale(escalaXcirculo, escalaYcirculo);
			cuadrado.setTexture(texturecirculo);
		}
		App.draw(cursor);
		// Mostramos la ventana
		App.display();
	}

	return 0;
}