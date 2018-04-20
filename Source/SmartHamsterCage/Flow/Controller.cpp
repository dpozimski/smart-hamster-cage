/*
 * Controller.cpp
 *
 * Created: 19.04.2018 17:34:09
 *  Author: d.pozimski
 */ 

Controller::Controller(Timer* timer) : timer(timer)
{

}

Timer* Controller::getTimer()
{
    return this->timer;
}
