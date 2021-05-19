#include "../include/drone.hh"



Drone Drone::Create(const char* File_Body,const char *File_Rotor1,const char *File_Rotor2,const char *File_Rotor3,const char *File_Rotor4)
{
  CoordsReadFromFile(File_Body, this->Body);

  CoordsReadFromFile(File_Rotor1, this->Rotor[0]);
  CoordsReadFromFile(File_Rotor2, this->Rotor[1]);
  CoordsReadFromFile(File_Rotor3, this->Rotor[2]);
  CoordsReadFromFile(File_Rotor4, this->Rotor[3]);

  return (*this);
}

Prism &Drone::ReturnRotor(int RotorNum){ return this->Rotor[RotorNum]; }

Cuboid &Drone::ReturnBody(){ return this->Body; }

Vector3 &Drone::ReturnBodyPosition(){ return this->Body.Position; }

Vector3 &Drone::ReturnRotorPosition(int RotorNum){ return this->Rotor[RotorNum].Position; }


/*bool ExecuteVerticalFlight(double time, Lacze:PzG:LaczeDoGNUPlota&)
{




  return true;
}


bool ExecuteHorizontalFlight(double time, Lacze:PzG:LaczeDoGNUPlota&)
{
  return true;
}*/
