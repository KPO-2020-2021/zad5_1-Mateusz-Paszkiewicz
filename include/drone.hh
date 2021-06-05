#pragma once

#include <chrono>
#include <thread>
#include <cmath>
#include <unistd.h>

#include "lacze_do_gnuplota.hh"
#include "handling.hh"
#include "matrix.hh"
#include "cuboid.hh"
#include "prism.hh"

/*          DRONE CLASS VISUALISATION (i tried xD)
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░█▀▀▀░░░░▀▄░░░░░░░░░░░░░░░░░░
░░Prism Rotor[2]░░░░░░░░▄█▀░░░░░░░░░░█░░░░░░░░░░░░░░░░░
░░░█▀▀▀▀▀▀█▄░░░░░░░░░░░░░░░░░░░░░░░░░░░▄░Prism Rotor[1]
░░▀░░░░░░░░░▀█░░░░░░░░░▐░░░░░░░░░░░░░░░░▌░░░░░░░░░░░░░░
░▌░░░░░░░░░░░░█░────────█░░░░░░░░░░░░░░░▌░░░░░░░░░░░░░░
░▌░░░░░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░▄▄░░░░░░░░░░░░░░░
░░▄░░░░░░░░░░░░▐░░░░░░░░░░░█▄▄░░░░▄▄▄▀░░░░░░░░░░░░░░░░░
░░░█░░░░░░░░░░░█░░░░░░░░░░░░░░▀▀▀▀─┐░░░░░░░░░░░░░░░░░░░
░░░│▀█░░░░░░░░█░░░░░░░░░░░░░░░░░░░░└──┐░░░░░░░░░░░░░░░░
░░░│░░░▀─┐▄▄▀░░░░░░░░░░░░░░░░░░░░░░░░░└─┐░░░░░░░░░░░░░░
░░░│░░░░░└┐░░░░░░░░░░░░░░░░░░░░░░░░░░░░░└─░░░░░░░░░░░░░
░░░│░░░░░░└┐░░░░░░░░░░░░░░░░░░░░░░░░░░░▄█▀▀▀▀▀█▄▄░░░░░░
░░░│░░░░░░░└┐░░░░░░░░░░░░░░░░░░░░░░░▄▀░░░░░░░░░░░▀█▄░░░
░░░│░░░░░░░░└┐░░Prism Rotor[3]░░░░░█░░░░░░░░░░░░░░░░█░░
░░░│░░░░░░░░▄│▄▄▄▄▄▄▄░░░░░░░░░░░░░░▌░░░░░░░░░░░░░░░░░▌░
░░░└┐░░░░░░░▄█▀▀▀░░░░▀▀▄░░░░░░░░░░░█░░Prism Rotor[0]░▌░
░░░░└┐░░░░▐▀░░░░░░░░░░░░▀█░░░░░░░░░░█░░░░░░░░░░░░░░░█░░
░░░░░└┐░░░▌░░░░░░░░░░░░░░░█░░░░░░░░░░▀▄▄░░░░░░░░░░░█│░░
░░░░░░│░░░▌░░░░░░░░░░░░░░░▐░░░░┌────────░▀▀▀▀▀▀▀▀▀▀░│░░
░░░░░░└┐░░▌░░░░░░░░░░░░░░░▐────┘░░░░░░░░░░░░░░░░░░░░│░░
░░░░░░░└┐░▀▄░░░░░░░░░░░░░░▀░░░░░░░░░░░░░░░░░░░░░░░░░│░░
░░░░░░░░│░░░█▄░░░░░░░░░░▄▀░░░░░░░░░░░░░░░░░░░░░░░░░░│░░
░░░░░░░░└┐░░░░▀▀▀▀▀▀▀▀▀▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░
░░░░░░░░░└┐░░░░┌─░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░
░░░░░░░░░░└┐░░░│░░░░░░░░░░░░░░░░Cuboid Body░░░░░░░░░│░░
░░░░░░░░░░░│░░░│░░░░░░░░░░░░░░░░░░░░░░░░░░░░┌───────┴░░
░░░░░░░░░░░└─┐░│░░░░░░░░░░░░░░░░░┌──────────┘░░░░░░░░░░
░░░░░░░░░░░░░└─┤░░░░░┌───────────┘░░░░░░░░░░░░░░░░░░░░░
*/


class Drone : public Cuboid, public Prism{
private:
  Cuboid Body;
  Prism Rotor[4];
  Vector3 Position;

  char *File_Names[6];
public:

  Drone Create(const char*[7]);                           // body

  Drone ChangeFiles(const char**);

  Drone Displacement(Vector3);

  void UpdateFiles();

  Vector3 PlanPath();

  bool SpinRotors(double);

  void Idle(PzG::LaczeDoGNUPlota);

  bool DrawVerticalFlight(Vector3, PzG::LaczeDoGNUPlota);

  bool DrawHorizontalFlight(Vector3, PzG::LaczeDoGNUPlota);


};
