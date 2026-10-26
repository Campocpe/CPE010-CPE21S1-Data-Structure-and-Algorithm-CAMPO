#ifndef PRINTER_SYSTEM_H
#define PRINTER_SYSTEM_H

#include <iostream>
#include <string>

// Templated circular array queue using typename T
template <typename T>
class queueArr {
private:
    T* q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    //assigns the values of the private variables and dynamically allocates the memory
    queueArr(size_t capacity) : q_capacity(capacity), q_size(0), q_front(0), q_back(-1) {
        q_array = new T[q_capacity];
    }
    
    //deletes the queue
    ~queueArr() {
        delete[] q_array;
    }
    //checks if the queue is empty
    bool empty() const { return q_size == 0; }

    //Checks if the queue is full by comparing current size to total capacity
    bool full() const { return q_size == q_capacity; }

    //returns the size of the array(number of items)
    size_t size() const { return q_size; }

    //returns the capacity of the array(the maximum size the array can hold)
    size_t capacity() const { return q_capacity; }

    //Returns the element at the front of the queue
    T Front() const {
        if (empty()) return T{};
        return q_array[q_front];
    }
    
    //adds contents to the queue
    void Enqueue(T newData) {
        if (full()) return;
        //modulo is used here to make sure the back wraps around in index 0 to loop the queue
        //it also assigns the index position of the array
        q_back = (q_back + 1) % q_capacity;
        //assigns the new data depending on the position/index of the data inserted in the queue
        q_array[q_back] = newData;
        q_size++; //increments the size
    }
    

    void Dequeue() {
        if (empty()) return;
        // Advances q_front and uses modulo to wrap around to index 0 when reaching capacity
        q_front = (q_front + 1) % q_capacity;
        q_size--;
    }
};

// Job representation
class Job {
public:
    int id;
    std::string userName;
    int pages;
    
    //adds the id, name and the ammount of pages inside the queue
    Job() : id(0), userName(""), pages(0) {}
    Job(int id, std::string userName, int pages)
        : id(id), userName(userName), pages(pages) {}

    //displays the contents of the job function
    void display() const {
        std::cout << "[Job ID: " << id << " | User: " << userName << " | Pages: " << pages << "]";
    }
};

// Printer class managing pending Job objects
class Printer {
private:
    //assigns jobs that are pending
    queueArr<Job> pendingJobs;

public:
    Printer(size_t capacity) : pendingJobs(capacity) {}
    
    //status getter functions that query the capacity and current count of the queue.
    bool isFull() const { return pendingJobs.full(); }
    bool isEmpty() const { return pendingJobs.empty(); }
    size_t getPendingCount() const { return pendingJobs.size(); }
    size_t getCapacity() const { return pendingJobs.capacity(); }

    //adds the job contents
    void addJob(const Job& job) {
        if (pendingJobs.full()) {
            std::cout << "\nError: Printer queue is full! Unable to add ";
            job.display();
            std::cout << std::endl;
            return;
        }

        pendingJobs.Enqueue(job);
        std::cout << "\nSuccessfully added job: ";
        job.display();
        std::cout << std::endl;
    }
    
    //processess the next job
    void processNextJob() {
        if (pendingJobs.empty()) {
            std::cout << "\nNo pending jobs to process." << std::endl;
            return;
        }

        Job currentJob = pendingJobs.Front();
        std::cout << "\nProcessing... ";
        currentJob.display();
        std::cout << std::endl;

        pendingJobs.Dequeue();
        std::cout << "Finished Job ID: " << currentJob.id << std::endl;
    }

    void processAllJobs() {
        if (pendingJobs.empty()) {
            std::cout << "\nNo pending jobs in the queue." << std::endl;
            return;
        }

        //loop that process all the jobs
        std::cout << "\n--- Processing All Pending Jobs ---" << std::endl;
        while (!pendingJobs.empty()) {
            processNextJob();
        }
        std::cout << "--- All print jobs completed ---" << std::endl;
    }
};

#endif // PRINTER_SYSTEM_H