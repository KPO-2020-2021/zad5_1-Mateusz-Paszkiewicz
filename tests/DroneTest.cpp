TEST_CASE("Drone PlanPath test")
{
  const char *WorkFileNames[7] = {      "../datasets/dat/PlikRoboczy_Dron1_Korpus.dat",
                                        "../datasets/dat/PlikRoboczy_Dron1_Rotor1.dat",
                                        "../datasets/dat/PlikRoboczy_Dron1_Rotor2.dat",
                                        "../datasets/dat/PlikRoboczy_Dron1_Rotor3.dat",
                                        "../datasets/dat/PlikRoboczy_Dron1_Rotor4.dat",
                                        "../datasets/dat/trasa_przelotu.dat",
                                        nullptr};

  Drone DroneTest=Drone();
  DroneTest.Create(WorkFileNames);

  DroneTest.ChangeFiles(WorkFileNames);

  double Path[3]={130, 130, 0};
  Vector3 PathVec=Vector3(Path);

  CHECK(DroneTest.PlanPath()==PathVec);
}
