#include <CustomStepper.h>

//Full constructor, just the first 4 parameters are necessary, they are the pins connected to the motor,
//the others are optional, and default to the following below
//the 5th paramater is the steps sequence, where the 1st element of the array is the number of steps
//it can have a maximum of 8 steps
//the 6th parameter is the SPR (Steps Per Rotation)
//the 7th parameter is the RPM
//the 8th parameter is the rotation orientation
CustomStepper stepper(8, 9, 10, 11, (byte[]){8, B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001}, 4075.7728395, 12, CW);

void setup(){
  //sets the RPM
  stepper.setRPM(1.924);
  //sets the Steps Per Rotation, in this case it is 64 * the 283712/4455 annoying ger ratio
  //for my motor (it works with float to be able to deal with these non-integer gear ratios)
  stepper.setSPR(4075.7728395);
}

void loop(){
  if (stepper.isDone())  {
    stepper.setDirection(CCW);
    //this will rotate until you stop it with another comand or set the direction to STOP
    stepper.rotate();
  }
  //this is very important and must be placed in your loop, it is this that makes the motor steps
  //when necessary
  stepper.run();
}
