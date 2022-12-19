class Point{
     public:
           float x;
           float y;
           float z;
           Point(float x,float y,float z):x(x),y(y),z(z){};
           Point(float x,float y):x(x),y(y),z(0){};
           Point():x(0),y(0),z(0){};
           Point operator+(Point p){
                Point pp=Point();
                pp.x=this->x+p.x;
                pp.y=this->y+p.y;
                pp.z=this->z+p.z;
                return pp;
                };
           Point operator-(Point p){
                Point pp=Point();
                pp.x=this->x-p.x;
                pp.y=this->y-p.y;
                pp.z=this->z-p.z;
                return pp;
                };
           Point operator*(float num){
                Point pp=Point();
                pp.x=this->x*num;
                pp.y=this->y*num;
                pp.z=this->z*num;
                return pp;
                };
           Point operator/(float num){
                Point pp=Point();
                pp.x=this->x/num;
                pp.y=this->y/num;
                pp.z=this->z/num;
                return pp;
                };
           Point operator+=(Point p){return *this+p;};
           Point operator-=(Point p){return *this-p;};
           Point operator*=(float num){return *this*num;};
           Point operator/=(float num){return *this/num;};
     };