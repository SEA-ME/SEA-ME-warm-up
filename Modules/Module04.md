# Module 04

## Exercise 00 : Multithreading
> Create a racing game that uses multi-threading to simulate the movement of multiple cars on a race track. Here's a general outline of how you could implement such an example:

1. Create a Car class: Create a C++ class that represents a car in the racing game. This class should have member variables for the car's position, speed, direction, and any other relevant information. You should also provide member functions to access and modify these variables.

2. Create a RaceTrack class: Create a C++ class that represents the race track in the game. This class should have member variables for the size of the track, the position of the finish line, and any other relevant information. You should also provide member functions to access and modify these variables.

3. Create a GUI: Use Qt's GUI tools to create a graphical user interface for the game. This interface should display the race track and the cars, and allow the user to start the race, pause the race, or exit the game.

4. Create a Thread class: Create a C++ class that represents a thread in the game. This class should contain a run() function that is called when the thread starts. Inside this function, you can use a loop to simulate the movement of the car on the race track. You can use a timer to control the speed of the car and update its position.

5. Connect the Threads to the Cars: Use Qt's signals and slots mechanism to connect the threads to the cars. For example, you can create a signal that gets emitted when the car's position changes, and a slot in the thread that receives this signal and updates the car's position accordingly.

6. Start the threads: When the user starts the race, create a new thread for each car and start the threads. Each thread will simulate the movement of its corresponding car on the race track.

7. Synchronize the threads: To ensure that the race is fair, you need to synchronize the threads so that they don't move too fast or too slow. You can use Qt's synchronization classes, such as QMutex or QSemaphore, to accomplish this.

Overall, creating a racing game using multi-threading in Qt involves creating C++ classes to represent the cars and the race track, creating threads to simulate the movement of the cars, and connecting the threads to the cars using signals and slots. By following these steps, you can create a fun and interactive racing game that showcases the power of multi-threading in Qt.

here are some pseudo code snippets to help illustrate the steps I outlined for a racing game using multi-threading in Qt:

```
class Car {
  public:
    int position;
    int speed;
    int direction;

    void move() {
        position += speed * direction;
        emit positionChanged(position);
    }

  signals:
    void positionChanged(int newPosition);
};
```
RaceTrack class:
```
class RaceTrack {
  public:
    int size;
    int finishLine;

    void setFinishLine(int newFinishLine) {
        finishLine = newFinishLine;
    }
};
```
GUI:
```
class RacingGame : public QMainWindow {
  public:
    RacingGame(QWidget *parent = 0);

  private slots:
    void startRace();
    void pauseRace();
    void exitGame();

  private:
    RaceTrack *raceTrack;
    QList<Car*> carList;
    QList<QThread*> threadList;
};
```
Thread class:
```
class CarThread : public QThread {
  public:
    CarThread(Car *car) : car(car) {}

    void run() {
        while (car->position < raceTrack->finishLine) {
            car->move();
            msleep(10); // Wait 10 milliseconds before moving again
        }
    }

  private:
    Car *car;
    RaceTrack *raceTrack;
};
```
Connecting threads to cars:
```
void RacingGame::startRace() {
    // Create a new thread for each car and start the threads
    foreach (Car *car, carList) {
        QThread *thread = new QThread();
        CarThread *carThread = new CarThread(car);
        carThread->moveToThread(thread);

        connect(car, &Car::positionChanged, carThread, &CarThread::updatePosition);
        connect(thread, &QThread::started, carThread, &CarThread::run);
        connect(carThread, &CarThread::finished, thread, &QThread::quit);
        connect(carThread, &CarThread::finished, carThread, &CarThread::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        threadList.append(thread);
        carThread->start();
    }
}
```
Synchronizing the threads:
```
void CarThread::run() {
    while (car->position < raceTrack->finishLine) {
        mutex.lock(); // Acquire a lock before moving the car
        car->move();
        mutex.unlock(); // Release the lock after moving the car
        msleep(10); // Wait 10 milliseconds before moving again
    }
}
```
Note that these code snippets are not complete and may require additional modifications to work properly in a Qt project. They are intended to provide a general idea of how to create a racing game using multi-threading in Qt.

<aside>
💡 Team up with others, join the force, let your creativity flow and make one exciting game! 
</aside>


## Evaluation Form
> Fill in this [Evaluation Form Module04](https://docs.google.com/forms/d/e/1FAIpQLSeNsRGq7I0ncIj1hlmbKm6bpQ4h1H95WHb_DBgp8DLaA9XA0g/viewform). **You need to collect 2 feedbacks from 2 peers from other than your own team**.
