#include "Cryption.hpp"
#include "../processes/Task.hpp"
#include "../fileHandling/ReadEnv.cpp"

int executeCryption(const std::string &taskData){
    Task task = Task::fromString(taskData);
    ReadEnv env;

    string envKey = env.getenv();
    int key = stoi(envKey);

    if(task.action == Action::ENCRYPT){
        char ch;
        while(task.f_stream.get(ch)){

            ch = (ch+key)%256;

            // when we did f_stream.get(ch) above, the pointer automatically went to the next character. so to replace the required character, we have to bring back the pointer to previous character and make it the current character
            task.f_stream.seekp(-1, ios::cur); 
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    } else{
        char ch;
        while(task.f_stream.get(ch)){
            ch = (ch-key + 256)%256;
            task.f_stream.seekp(-1, ios::cur);
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    }
    return 0;
}