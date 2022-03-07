class ParkingSystem {
public:
    // vector stores the parking space
    ParkingSystem(int big, int medium, int small) {
        parking[0] = big;
        parking[1] = medium;
        parking[2] = small;
    }
    
    // check the space if available
    // park the car and decrement it
    // otherwise return false
    bool addCar(int carType) {
        if(parking[carType-1] > 0){
            parking[carType-1]--;
            return true;
        } else{
            return false;
        }
    }
    
private:
    vector<int> parking = {0,0,0};
    
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
