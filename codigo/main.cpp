#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using std::cout;

int threshold_value = 0;
int threshold_type = 0;
int const max_value = 255;
int const max_type = 1;
int const max_binary_value = 255;
Mat src, src_gray, dst, src_norm;
const char* window_name = "Proyecto C++";
const char* trackbar_type = "Type: \n Imagen en Binario";
const char* trackbar_value = "Valor de corte: 0 - 255";

static void Threshold_Demo( int, void* )
{
    
    threshold(src_gray, dst, threshold_value, max_binary_value, threshold_type );
    imshow( window_name, dst );
}

int main( int argc, char** argv )
{
    String imageName("horizonte6.jpg"); // Nombre de la imagen

    if (argc > 1)
    {
        imageName = argv[1];
    }
    src = imread(imageName, IMREAD_COLOR ); // Carga de la imagen

    if (src.empty())
    {
        cout << "No se encontro la imagen con ese nombre: " << imageName << std::endl;
        return -1;
    }

    // MOSTRANDO IMAGEN ORIGINAL
    imshow("Imagen original", src);
    // CONVERTIR IMAGEN A ESCALA DE GRISES
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    // CREAR VENTANA PARA VER EL RESULTADO
    namedWindow( window_name, WINDOW_AUTOSIZE );
    // MOSTRANDO LA IMAGEN EN ESCALA DE GRISES
    imshow("Imagen en escala de grises", src_gray);
    // NORMALIZAR LA IMAGEN EN ESCALA DE GRISES
    src_gray.convertTo(src_norm, CV_32F, 1.0 / 255, 0);
    // MOSTRANDO LA IMAGEN NORMALIZADA ENTRE 0-1    
    imshow("Imagen Normalizada", src_norm);
    // BINARIZACION DE LA IMAGEN NORMALIZADA   
    createTrackbar( trackbar_value, window_name, &threshold_value, max_value, Threshold_Demo ); 
    Threshold_Demo( 0, 0 ); // llamado a la funcion de inicio
    waitKey();
    return 0;
}
