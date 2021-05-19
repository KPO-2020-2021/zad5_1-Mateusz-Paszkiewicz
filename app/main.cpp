// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../external/doctest/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>

#include "lacze_do_gnuplota.hh"
#include "exampleConfig.h"
#include "handling.hh"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
#include "cuboid.hh"
#include "prism.hh"
#include "drone.hh"


#define CUBOID_MODEL_FILE      "../datasets/bryly_wzorcowe/szescian.dat"
#define PRISM6_MODEL_FILE      "../datasets/bryly_wzorcowe/graniastoslup6.dat"
#define DRONE_BODY_FILE        "../datasets/dat/korpus_drana1.dat"

#define WORK_FILE__DRONE1_BODY    "../datasets/dat/PlikRoboczy_Dron1_Korpus.dat"
#define WORK_FILE__DRONE1_ROTOR1  "../datasets/dat/PlikRoboczy_Dron1_Rotor1.dat"
#define WORK_FILE__DRONE1_ROTOR2  "../datasets/dat/PlikRoboczy_Dron1_Rotor2.dat"
#define WORK_FILE__DRONE1_ROTOR3  "../datasets/dat/PlikRoboczy_Dron1_Rotor3.dat"
#define WORK_FILE__DRONE1_ROTOR4  "../datasets/dat/PlikRoboczy_Dron1_Rotor4.dat"

#define ACTUAL_FILE__DRONE1_BODY    "../datasets/dat/PlikWlasciwy_Dron1_Korpus.dat"
#define ACTUAL_FILE__DRONE1_ROTOR1  "../datasets/dat/PlikWlasciwy_Dron1_Rotor1.dat"
#define ACTUAL_FILE__DRONE1_ROTOR2  "../datasets/dat/PlikWlasciwy_Dron1_Rotor2.dat"
#define ACTUAL_FILE__DRONE1_ROTOR3  "../datasets/dat/PlikWlasciwy_Dron1_Rotor3.dat"
#define ACTUAL_FILE__DRONE1_ROTOR4  "../datasets/dat/PlikWlasciwy_Dron1_Rotor4.dat"

#define ROUTE_FILE "../datasets/dat/trasa_przelotu.dat"




int main() {

  PzG::LaczeDoGNUPlota  Lacze;

  Drone Drone1=Drone();
  Drone1.Create(
    WORK_FILE__DRONE1_BODY,
    WORK_FILE__DRONE1_ROTOR1,
    WORK_FILE__DRONE1_ROTOR2,
    WORK_FILE__DRONE1_ROTOR3,
    WORK_FILE__DRONE1_ROTOR4
  );

  Lacze.DodajNazwePliku(ACTUAL_FILE__DRONE1_ROTOR1);

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(0, 200);
  Lacze.UstawZakresY(0, 200);
  Lacze.UstawZakresZ(0, 120);

  Lacze.Rysuj();

  std::cin.ignore(10000,'\n');


  return 0;
}
