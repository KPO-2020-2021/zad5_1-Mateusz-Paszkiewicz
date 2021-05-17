TEST_CASE("Cuboid Class parametric Contructor Test")
{
  double arr[8][3]={{2,3,3},{22,3,3},{2,18,3},{22,18,3},{2,18,28},{22,18,28},{2,3,28},{22,3,3}};
  Cuboid test=Cuboid(arr);

  CHECK(test(0,0) == 2);
  CHECK(test(0,1) == 3);
  CHECK(test(0,2) == 3);

  CHECK(test(1,0) == 22);
  CHECK(test(1,1) == 3);
  CHECK(test(1,2) == 3);

  CHECK(test(2,0) == 2);
  CHECK(test(2,1) == 18);
  CHECK(test(2,2) == 3);

  CHECK(test(3,0) == 22);
  CHECK(test(3,1) == 18);
  CHECK(test(3,2) == 3);

  CHECK(test(4,0) == 2);
  CHECK(test(4,1) == 18);
  CHECK(test(4,2) == 28);

  CHECK(test(5,0) == 22);
  CHECK(test(5,1) == 18);
  CHECK(test(5,2) == 28);

  CHECK(test(6,0) == 2);
  CHECK(test(6,1) == 3);
  CHECK(test(6,2) == 28);

  CHECK(test(7,0) == 22);
  CHECK(test(7,1) == 3);
  CHECK(test(7,2) == 3);


}

TEST_CASE("Cuboid Class parametric Contructor Test")
{
  double arr[8][3]={{2,3,3},{22,3,3},{2,18,3},{22,18,3},{2,18,28},{22,18,28},{2,3,28},{22,3,3}};
  Cuboid test=Cuboid(arr);


  double angle=90;

  test.AngleTrans(angle*M_PI/180, 'x');


  CHECK(test(0,0) == 2);
  CHECK(test(0,1) == -3);
  CHECK(test(0,2) == 3);

  CHECK(test(1,0) == 22);
  CHECK(test(1,1) == -3);
  CHECK(test(1,2) == 3);

  CHECK(test(2,0) == 2);
  CHECK(test(2,1) == -3.0);
  CHECK(test(2,2) == 18);

  CHECK(test(3,0) == 22);
  CHECK(test(3,1) == -3);
  CHECK(test(3,2) == 18);

  CHECK(test(4,0) == 2);
  CHECK(test(4,1) == -28);
  CHECK(test(4,2) == 18);

  CHECK(test(5,0) == 22);
  CHECK(test(5,1) == -28);
  CHECK(test(5,2) == 18);

  CHECK(test(6,0) == 2);
  CHECK(test(6,1) == -28);
  CHECK(test(6,2) == 3);

  CHECK(test(7,0) == 22);
  CHECK(test(7,1) == -3);
  CHECK(test(7,2) == 3);


}
