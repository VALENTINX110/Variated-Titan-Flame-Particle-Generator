//by VALENTINX110
//insipred by geenium's circle point coordinates generator https://github.com/geenium/circle-coords/blob/master/circle_coords.js
#include <iostream>
#include <fstream>
#include <cmath>
#define pi 3.14159265
using namespace std;

/* inspirat după programul javascript al lui geenium de pe github: 

- Acest algoritm funcționeaza în felul următor:
    1) se citesc parametrii (radius și pointsle);
    2) se obtine unghiul rație (unghiul rezultat din împarțirea unghiului cercului -2pi- la numarul pointslor);
    3) se înmulțește unghiul rație cu contorul ”i” pentru a calcula unghiul de la origine pana la punctul reprezentat de i
    4) se calculează sinusul și cosinusul unghiului (coordonatele unui punct A( x , y ) == A( cos(unghi) , sin(unghi) ) );
    6) se repetă de numărul de ori egal cu numărul de points.
*/

ofstream function("titan_par.mcfunction");
ofstream running("titanrun.mcfunction");
double unghi, unghi1, unghi2, x, z, radius, x1, z1;
int points, i,j, score=0, intersections; 
double round(double var) {
    double value = (int)(var * 1000 + .5);
    return (double)value / 1000;
}
void generate(double unghi1, double unghi2) {
    int ii,jj;
    for (ii=1;ii<=intersections;ii++) {
        unghi = unghi1 + (2*pi/intersections)*ii; 
        x = round(radius*cos(unghi));
        z = round(radius*sin(unghi));
        x1 = -1*x;
        z1 = -1*z;
        function<<"execute if score @s titanPar matches "<<score<<" run particle flame "<<"~"<<x<<" ~0.1 ~"<<z<<' '<<x1<<" 0 "<<z1<<" 0.055 0 force"<<'\n';
    }
    for (jj=intersections;jj>=1;jj--) {
        unghi = unghi2 + (2*pi/intersections)*jj; 
        x = round(radius*cos(unghi));
        z = round(radius*sin(unghi));
        x1 = -1*x;
        z1 = -1*z;
        function<<"execute if score @s titanPar matches "<<score<<" run particle flame "<<"~"<<x<<" ~0.1 ~"<<z<<' '<<x1<<" 0 "<<z1<<" 0.06 0 force"<<'\n';
    }
}
int main() {
    cout<< "> Radius in blocks: "; cin>>radius; cout<<'\n'<<'\n';
    cout<< "> Number of points: "; cin>>points; cout<<'\n'<<'\n';
    cout<< "> Number of intersections: "; cin>>intersections; cout<<'\n'<<'\n';
    i=1; j=points;
    while (i<=points&&j>=1) {
        unghi1= (2*pi/points)*i;
        unghi2= (2*pi/points)*j;
        generate(unghi1,unghi2);
        i++; j--;
        function<<'\n';
        score++;
    }
    running<<"execute as @a[tag=titan] at @s if score @s titanPar matches 0.."<<score<<" run scoreboard players add @s titanPar 1"<<'\n';
    score++;
    running<<"execute as @a[tag=titan] at @s if score @s titanPar matches "<<score<<".. run scoreboard players set @s titanPar 0"<<'\n';
    score--;
    running<<"execute as @a[tag=titan] at @s if score @s titanPar matches 0.."<<score<<" run function test:titan_par";
    cout<<"gata :)";
    return 0;
}