// materiales.cpp : Defines the entry point for the console application.
/*
	Calculadora resistencia de los materiales 0.1
	En esta versión del programa se busca calcular el diámetro de la sección del vastago en una válvula hidráulica,
	a partir de un conjunto de parametros.
*/

#include "stdafx.h"
#include <iostream>


const double pi = 3.1415926535897;

double areaDesdeDiametro(double diametro) { return (pi * std::pow((diametro), 2.0)) / 4.0; }

double areaADiametro(double area) { return sqrt(4 * area / pi); }

double m2Amm2(double valor) { return valor / 1'000'000.0; }

double calcularSeccion(double presion, double diametroEntrada, double sigmaFluencia, double coeficienteSeg)
{
	double sigmaDiseno = sigmaFluencia / coeficienteSeg;
	double num = 2 * m2Amm2(presion) * std::pow(diametroEntrada, 2.0);
	double den = sigmaDiseno + 2 * m2Amm2(presion);
	return std::sqrt(num / den);

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
		<< " mm.\n";
	
	std::cout << "Press enter to exit...\n";

	std::cin.get();
	std::cin.get();
	
	

    return 0;
}

