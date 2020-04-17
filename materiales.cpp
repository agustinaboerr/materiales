// materiales.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


const double pi = 3.1415926535897;

double calcularSeccion(double presion, double diametroEntrada, double sigmaFluencia, double coeficienteSeg)
{
	double sigmaDiseno = sigmaFluencia / coeficienteSeg;
	double area = pi * std::pow((diametroEntrada / 2.0), 2.0);
	double fuerza = (presion / 1'000'000) * area;
	return fuerza / sigmaDiseno;

}


int main()
{
	double presion{0.0};
	double diametroEntrada{0.0};
	double sigmaFluencia{0.0};
	double coeficienteSeg{0.0};

	
	std::cout << "Bienvenido a la calculadora de materiales\n";
	std::cout << "Ingrese presion (kg/m^2): ";
	std::cin >> presion;
	std::cout << "Ingrese diametro de entrada (mm): ";
	std::cin >> diametroEntrada;
	std::cout << "Ingrese sigma de fluencia (kg'/mm^2): ";
	std::cin >> sigmaFluencia;
	std::cout << "Ingrese coeficiente de seguridad: ";
	std::cin >> coeficienteSeg;

	std::cout << "La seccion debe medir: " << calcularSeccion(presion, diametroEntrada, sigmaFluencia, coeficienteSeg)
		<< " mm^2.\n";

	std::cout << "Press enter to exit...\n";

	std::cin.get();
	std::cin.get();
	
	

    return 0;
}

