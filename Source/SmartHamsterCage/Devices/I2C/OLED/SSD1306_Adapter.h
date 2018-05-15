/*
 * SSD1306_Adapter.h
 *
 * Created: 15.05.2018 19:46:49
 *  Author: d.pozimski
 */ 


#ifndef SSD1306_ADAPTER_H_
#define SSD1306_ADAPTER_H_


class SSD1306Adapter : public Device
{
    public:
        SSD1306Adapter();
        void init() override;    
    
};



#endif /* SSD1306_ADAPTER_H_ */