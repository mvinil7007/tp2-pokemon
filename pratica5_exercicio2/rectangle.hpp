#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
    private:
        float _length;
        float _width;

    public:
        
        Rectangle();
        
        // Métodos Get
        float getLength();
        float getWidth();
        
        // Métodos Set 
        void setLenght(float length); 
        void setWidth(float width);
        
        // Métodos de cálculo
        float calcPerimeter();
        float calcArea();
};

#endif