#include "../include/drone.hh"

#define TIME_UNIT 1 //in seconds
#define MAX_HEIGHT 80
#define VELOCITY 10   //Units per second


Drone Drone::Create(const char* File_Names[7])
{
  CoordsReadFromFile(File_Names[0], this->Body);
  CoordsReadFromFile(File_Names[1], this->Rotor[0]);
  CoordsReadFromFile(File_Names[2], this->Rotor[1]);
  CoordsReadFromFile(File_Names[3], this->Rotor[2]);
  CoordsReadFromFile(File_Names[4], this->Rotor[3]);

  return (*this);
}

void Drone::UpdateFiles()
{
  SaveCoordsToFile(this->File_Names[0],     this->Body);
  SaveCoordsToFile(this->File_Names[1], this->Rotor[0]);
  SaveCoordsToFile(this->File_Names[2], this->Rotor[1]);
  SaveCoordsToFile(this->File_Names[3], this->Rotor[2]);
  SaveCoordsToFile(this->File_Names[4], this->Rotor[3]);
}


Drone Drone::Displacement(Vector3 Trans)
{
  (*this).Body=(*this).Body+Trans;
  (*this).Position=(*this).Position+Trans;

  for(int i=0; i<4; i++)
    (*this).Rotor[i]=(*this).Rotor[i]+Trans;

  return (*this);
}

Vector3 Drone::PlanPath()
{
  Vector3 PathCoordsVecStart=Vector3();
  Vector3 PathCoordsVecFinish=Vector3();

  std::ifstream  fin;

  fin.open(this->File_Names[6]);
  if (!fin.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << this->File_Names[6] << "\"" << std::endl
   << ":(  nie powiodla sie." << std::endl;
    return 0;
    }

 fin.ignore(1000,'\n');
 fin.ignore(1000,'\n');

 fin>>PathCoordsVecStart[0]; fin>>PathCoordsVecStart[1]; fin>>PathCoordsVecStart[2];
 fin>>PathCoordsVecFinish[0]; fin>>PathCoordsVecFinish[1]; fin>>PathCoordsVecFinish[2];

 fin.close();

 return PathCoordsVecFinish-PathCoordsVecStart;
}

bool Drone::DrawAnimation(Vector3 PathVector, PzG::LaczeDoGNUPlota Lacze)
{
  Vector3 StartingCoords=this->Body.GetPosition();
  double VerticalTime   = MAX_HEIGHT / VELOCITY;

  for(int timer=0; timer<VerticalTime || this->Body.GetPosition()==StartingCoords+PathVector ; timer+=TIME_UNIT)
    {
      this->Displacement(PathVector/VerticalTime);
      this->UpdateFiles();

      Lacze.Rysuj();

      std::this_thread::sleep_for(std::chrono::seconds(TIME_UNIT));
    }

  if(this->Body.GetPosition()==StartingCoords+PathVector)
    return true;
  else
    return false;
}
