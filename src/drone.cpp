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

void Drone::UpdateFiles(const char* File_Body,const char *File_Rotor1,const char *File_Rotor2,const char *File_Rotor3,const char *File_Rotor4)
{
  SaveCoordsToFile(File_Body, this->Body);

  SaveCoordsToFile(File_Rotor1, this->Rotor[0]);
  SaveCoordsToFile(File_Rotor2, this->Rotor[1]);
  SaveCoordsToFile(File_Rotor3, this->Rotor[2]);
  SaveCoordsToFile(File_Rotor4, this->Rotor[3]);

}


Drone Drone::Displacement(Vector3 Trans)
{
  (*this).Body=(*this).Body+Trans;
  (*this).Position=(*this).Position+Trans;

  for(int i=0; i<4; i++)
    (*this).Rotor[i]=(*this).Rotor[i]+Trans;

  return (*this);
}


/*bool ExecuteVerticalFlight(double time, Lacze:PzG:LaczeDoGNUPlota&)
{
  return true;
}

bool ExecuteHorizontalFlight(double time, Lacze:PzG:LaczeDoGNUPlota&)
{
  return true;
}*/
