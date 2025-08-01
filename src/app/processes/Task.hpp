#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../fileHandling/IO.hpp"

using namespace std;

enum class Action
{
    ENCRYPT,
    DECRYPT
};

struct Task
{
    string filePath;
    fstream f_stream;
    Action action;

    Task(fstream &&stream, Action act, string filePath)
        : filePath(filePath), f_stream(std::move(stream)), action(act) {}

    // serialize
    string toString()
    {
        ostringstream oss;
        oss << filePath << "," << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");

        return oss.str();
    }

    // deserialize
    static Task fromString(const string &taskData)
    {
        istringstream iss(taskData);
        string filePath;
        string actionStr;

        if (getline(iss, filePath, ',') && getline(iss, actionStr))
        {
            Action action = (actionStr == "ENCRYPT") ? Action::ENCRYPT : Action::DECRYPT;
            IO io(filePath);
            fstream f_stream = std::move(io.getFileStream());
            if (f_stream.is_open())
            {
                return Task(std::move(f_stream), action, filePath);
            }
            else
            {
                throw runtime_error("Failed to open file: " + filePath);
            }
        }
        else
        {
            throw runtime_error("Invalid task data format");
        }
    }
};

#endif