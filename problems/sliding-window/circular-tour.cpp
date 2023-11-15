

// In the provided solution, the difict variable is used to keep track of the accumulated deficit or shortfall in the balance of petrol during the iteration through the petrol pumps.It helps in determining whether there exists a valid starting point that allows the truck to complete the circular tour without running out of petrol.

// Here's how the difict variable is used in the algorithm:

// balance is the variable that tracks the balance of petrol as the truck moves from one petrol pump to another.If the balance becomes negative, it means that the truck couldn't make it from the current starting point to the current petrol pump, so the starting point is adjusted to the next petrol pump, and the balance is reset to 0.

// difict is used to accumulate the negative balances(shortfalls) encountered during the iteration.Whenever the balance becomes negative and the starting point is adjusted, the shortfall is added to difict.This represents the total deficit in petrol balance as the truck moves through the circular tour.

// After the loop, difict contains the total accumulated deficit, and balance represents the remaining petrol balance when the loop ends.

// The condition if (difict + balance >= 0) checks if the total accumulated deficit, along with the remaining balance, is greater than or equal to zero.If this condition is true, it means that the truck can complete the tour without running out of petrol, and the starting point is valid.In this case, the start variable is returned as the starting point.

// If the condition is not met, it means that there is no valid starting point to complete the tour, and -1 is returned to indicate that it's not possible to complete the circular tour.


struct petrolPump
{
  int petrol;
  int distance;
};

int tour(petrolPump p[], int n) {
  int balance = 0;
  int start = 0;
  int difict = 0;

  for (int current = 0; current < n; current++) {
    balance += p[current].petrol - p[current].distance;

    if (balance < 0) {
      start = current + 1;
      difict += balance;
      balance = 0;
    };
  }

  if (difict + balance >= 0) {
    return start;
  }
  else {
    return -1;
  }
}
