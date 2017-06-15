#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_


class AbstractVM
{
public:

    void run();

private:

    void getInput();

    int _buffSize = 512;
};

#endif //_MESSAGE_HPP_
