/*Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.
Implement the ParkingSystem class:
ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class.
The number of slots for each parking space are given as part of the constructor.
bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot.
carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively.
A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.
*/
 

/*Approach:
Just subtract the count of the given car type, and return true if the count is greater than 0 else return false.
In ParkingSystem function b,m and s would be representing the count of big, medium and small parking.*/

class ParkingSystem {
public:
    int b; int m; int s;

    ParkingSystem(int big, int medium, int small) {
        b=big; m=medium; s=small;
    }
    
    bool addCar(int carType) {
        
        if(carType==1 && b>0){
            b--; return true;
        }
        if(carType==2 && m>0){
            m--; return true;
        }
        if(carType==3 && s>0){
            s--; return true;
        }
        return false;
    }
};
