#define G 6.674e-11
#define M 5.972e24
long double atm_pres(long double dist, long double latt, long double longt)
{
    //Atmospheric pressure at distance from earth
    /*
    P_h = P_0 x E^((-m x g x h)/(k x T))
    P_h=Pressure at height
    P_0=Sea level pressure
    g=acceleration due to gravity
    k=Boltzmann's constant (ideal gas constant divided by Avogadro's number)
    T=absolute temperature
    m=mass of one air molecule
    */
}
long double grav_accl(long double dist, long double latt, long double longt)
{
    //Value of g at distance from earth
}
long double air_resist(long double dist, long double latt, long double longt)
{
    //Air resistance at distance from earth - it's variable
}
long double temp(long double dist, long double latt, long double longt)
{
    //Temperature at distance
}
long double force(long double payload, long double dist, long double latt, long double longt)
{
    //Force required to push at this point of space
    atm_pres(dist, latt, longt);
    grav_accl(dist, latt, longt);
    air_resist(dist, latt, longt);
    temp(dist, latt, longt);
}
long double uforce(long double payload, long double dist, long double latt, long double longt)
{
    //Pull up force required to push at this point of space
    atm_pres(dist, latt, longt);
    grav_accl(dist, latt, longt);
    air_resist(dist, latt, longt);
    temp(dist, latt, longt);
}