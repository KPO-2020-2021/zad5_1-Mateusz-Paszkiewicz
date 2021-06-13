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
#include <cstdlib>
#include <fstream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>

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
#define PLAIN_FILE "../datasets/bryly_wzorcowe/plaszczyzna.dat"


const char *WorkFileNames[7] = {      WORK_FILE__DRONE1_BODY,
                                      WORK_FILE__DRONE1_ROTOR1,
                                      WORK_FILE__DRONE1_ROTOR2,
                                      WORK_FILE__DRONE1_ROTOR3,
                                      WORK_FILE__DRONE1_ROTOR4,
                                      ROUTE_FILE,
                                      nullptr };

const char *ActualFileNames[7] = {  ACTUAL_FILE__DRONE1_BODY,
                                    ACTUAL_FILE__DRONE1_ROTOR1,
                                    ACTUAL_FILE__DRONE1_ROTOR2,
                                    ACTUAL_FILE__DRONE1_ROTOR3,
                                    ACTUAL_FILE__DRONE1_ROTOR4,
                                    ROUTE_FILE,
                                    nullptr };

int main() {

  PzG::LaczeDoGNUPlota  Lacze;

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawRotacjeXZ(50,250); // Tutaj ustawiany jest widok


  Lacze.DodajNazwePliku(WORK_FILE__DRONE1_BODY);
  Lacze.DodajNazwePliku(WORK_FILE__DRONE1_ROTOR1);
  Lacze.DodajNazwePliku(WORK_FILE__DRONE1_ROTOR2);
  Lacze.DodajNazwePliku(WORK_FILE__DRONE1_ROTOR3);
  Lacze.DodajNazwePliku(WORK_FILE__DRONE1_ROTOR4);
  Lacze.DodajNazwePliku(ROUTE_FILE);
  Lacze.DodajNazwePliku(PLAIN_FILE);

  Lacze.UstawZakresX(0, 200);
  Lacze.UstawZakresY(0, 200);
  Lacze.UstawZakresZ(0, 90);

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.


  Drone Drone1=Drone();
  Drone1.Create(ActualFileNames);

  Drone1.ChangeFiles(WorkFileNames);

  double ascension[3]={0,0,80};
  Vector3 AscensionVector=Vector3(ascension);
  double descent[3]={0,0,-80};
  Vector3 DescentVector=Vector3(descent);

  Vector3 PathVec=Drone1.PlanPath();

  Drone1.DrawDroneRotation(90, Lacze);
  getchar();
  Drone1.DrawVerticalFlight(AscensionVector, Lacze);
  Drone1.Idle(2, Lacze);
  Drone1.DrawHorizontalFlight(PathVec, Lacze);
  Drone1.Idle(2, Lacze);
  Drone1.DrawVerticalFlight(DescentVector, Lacze);


  return 0;
}
