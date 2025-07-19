#include "ProcessManagement.hpp"
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include "../encryptDecrypt/Cryption.hpp"

ProcessManagement::ProcessManagement(){}

// task is a unique pointer which means that there can only be one process which can point to a particular task
// i.e. two process cannot simultaneouously access one task
// address of task cannot be copied. Only the ownership can be passed on by using move() function.
bool ProcessManagement::submitToQueue(unique_ptr<Task> task){
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks(){
    while(!taskQueue.empty()){
        auto taskToExecute = std::move(taskQueue.front()); // passing the ownership is necessary due to unique pointer
        taskQueue.pop();
        cout << "Executing task: " << taskToExecute->toString() << endl;
        executeCryption(taskToExecute->toString());
    }
}
