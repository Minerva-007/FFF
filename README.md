# FFF what?
Form Factor Finder is a C++ program that finds the form factor for geometries existing in two-dimension. 
## What's form factor?
In a system undergoing radiative transfer, it is essential to know what percentage of radiation emitted from one surface reaches the other. This is called the Form Factor of the configuration.
Form factor is important in heat transfer since it is also a type of efficiency (and engineers have a thing for efficiencies).

##There are two ways of finding Form Factor.

* Analytical solution
There exists calculus which determines the form factor by implementing path integrals. Further analysis is done by using Reciprocity theorem.

* Engineer's 1337 hax0r
Since it is a measure of how much radiation emitted by surface A hits surface B, one can simulate radiations leaving one surface and checking if these ever hit the other side.
More rays of radiation tested + more variation in direction of emission = better estimation of form factor.

This program does the latter.

## But how does it do it?
The code contains the maths governing the simulation. Basically, a solution for intersection of a ray and a line is considered and then tested if the intersection point lies within the line segment. Count and then measure probability.


Enjoy.
- Minerva
