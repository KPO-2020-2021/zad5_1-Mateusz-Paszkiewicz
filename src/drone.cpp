#include "../include/drone.hh"

#define TIME_UNIT 10.00 //in seconds
#define TIME_UNIT_INT 10
#define MAX_HEIGHT 80
#define VELOCITY 20   //Units per second


Drone Drone::Create(const char* File_Names[7])
{
  CoordsReadFromFile(File_Names[0], this->Body);
  CoordsReadFromFile(File_Names[1], this->Rotor[0]);
  CoordsReadFromFile(File_Names[2], this->Rotor[1]);
  CoordsReadFromFile(File_Names[3], this->Rotor[2]);
  CoordsReadFromFile(File_Names[4], this->Rotor[3]);

  return (*this);
}

Drone Drone::ChangeFiles(const char* File_Names[7])
{
  this->File_Names[0]=const_cast <char *>(File_Names[0]);
  this->File_Names[1]=const_cast <char *>(File_Names[1]);
  this->File_Names[2]=const_cast <char *>(File_Names[2]);
  this->File_Names[3]=const_cast <char *>(File_Names[3]);
  this->File_Names[4]=const_cast <char *>(File_Names[4]);
  this->File_Names[5]=const_cast <char *>(File_Names[5]);
  this->File_Names[6]=const_cast <char *>(File_Names[6]);

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

  if(this->File_Names[5]==nullptr){
    std::cout<<"No file name!"<<std::endl;
    return 0;
  }


  fin.open(this->File_Names[5]);
  if (!fin.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << this->File_Names[5] << "\"" << std::endl
   << ":(  nie powiodla sie." << std::endl;
    return 0;
    }

 fin.ignore(1000,'\n');

 fin>>PathCoordsVecStart[0]; fin>>PathCoordsVecStart[1]; fin>>PathCoordsVecStart[2];
 fin>>PathCoordsVecFinish[0]; fin>>PathCoordsVecFinish[1]; fin>>PathCoordsVecFinish[2];

 fin.close();

 return PathCoordsVecFinish-PathCoordsVecStart;
}

bool Drone::DrawVerticalFlight(Vector3 PathVector, PzG::LaczeDoGNUPlota Lacze)
{
  Vector3 StartingCoords=this->Body.GetPosition();
  double VerticalTime   = MAX_HEIGHT / VELOCITY;

  for(double timer=0; timer<=VerticalTime  ; timer+=TIME_UNIT/1000)
    {
      this->Displacement(PathVector/VerticalTime*TIME_UNIT/1000);
      this->UpdateFiles();

      Lacze.Rysuj();

      std::this_thread::sleep_for(std::chrono::milliseconds(TIME_UNIT_INT));
    }

  if(this->Body.GetPosition()==StartingCoords+PathVector)
    return true;
  else
    return false;
}



bool Drone::DrawHorizontalFlight(Vector3 PathVector, PzG::LaczeDoGNUPlota Lacze)
{
  Vector3 StartingCoords=this->Body.GetPosition();
  double VerticalTime   = PathVector.Length() / VELOCITY;

  for(double timer=0; timer<=VerticalTime  ; timer+=TIME_UNIT/1000)
    {
      this->Displacement(PathVector/VerticalTime*TIME_UNIT/1000);
      this->UpdateFiles();

      Lacze.Rysuj();

      std::this_thread::sleep_for(std::chrono::milliseconds(TIME_UNIT_INT));
    }

  if(this->Body.GetPosition()==StartingCoords+PathVector)
    return true;
  else
    return false;
}
