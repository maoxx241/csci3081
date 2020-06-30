/**
 * @file mainpage.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
/*! \mainpage Transit Simulator
 *
 * \section introduction
 *
 * It is a Transit Simulation project writen in C++.
 * \section  User Guide(instructions)
 * \subsection Step by step for instructions for CSE Labs machines or vole users.
 * 1.Navigate to base project directory(project/)
 * 
 * 2.Make and run the server:
 * 
 * $ cd src
 * 
 * $ make 
 * 
 * $ cd ..
 * 
 * $./build/bin/vis_sim <port_number>
 * 
 * You must run by doing ./build/bin/vis_sim <port_number>.
 * 
 * You cannot cd to bin/ and run ./vis_sim <port_number>
 * 
 * <port_number> below should be a number above 8000 that includes
 * the last 3 digits of your student id. So, if your student id number
 * is: 1459345, use 8345, or 9345
 * 
 * 3.Run your browser on vole or CSE Labs machine,
 * and enter following address in the address bar of your browser (Firefox/Chrome):
 * http://127.0.0.1:<port_number>/web_graphics/project.html
 * 
 * 4.Click the start and pause and resume buttons on the webpage to use the simulator
 * \subsection Step by step instructions for ssh users
 * You can SSH using a Windows machine with Git Bash.
 * 
 * <port_number> below should be a number above 8000 that includes the last 3 digits of your student id.
 * So, if your student id number is: 1459345, use 8345, or 9345
 * 
 * ssh -L <port number>:127.0.0.1:<port_number> <x500>@<cse_labs_computer>.cselabs.umn.edu
 * 
 * 1.Navigate to base project directory(project/)
 * 
 * 2.make and start server:
 * 
 * $ cd src
 * 
 * $ make 
 * 
 * $ cd ..
 * 
 * $./build/bin/vis_sim <port_number>
 * 
 * You must run by doing ./build/bin/vis_sim <port_number>.
 * 
 * You cannot cd to bin/ and run ./vis_sim <port_number>
 * 
 * 3.avigate to the following address into the address bar of a browser (Firefox/Chrome) 
 * running on your LOCAL machine (e.g, your PC):
 * http://127.0.0.1:<port_number>/web_graphics/project.html
 * 
 * 4.Click the start and pause and resume buttons on the webpage to use the simulator
 * \subsection To Compile and Run Unit Tests created with Google Test:
 * 
 * cd tests
 * 
 * make
 * 
 * ../build/bin/unittest
 * \subsection Style Check:
 * [path_to_cpplint]/cpplint/cpplint-cse.sh --root=[path_target_dir] [file_name]
 * \section Design
 * \subsection factory_design
 * \subsection ConcreteBusFactory
 * in the ConcreteBusFactory it will generate a new bus object based on the capacity of the bus.
 * it will randomly generate. But it also can generate a bus object with three subclass of the bus 
 * class base on bustype variable.
 * three subclass is small bus, regular bus, and large bus.
 * 
 * pro:
 * 
 * Product names are isolated in the implementation of the Concrete Factory,
 * clients use the instances through their abstract interfaces.
 * Exchanging product families is easy.
 * 
 * con:
 * 
 * Adding a new product requires extending the interface which
 * implies that all of its derived concrete classes also must change.
 * \subsection AbstractBusFactory
 * Different from the above method. All three subclasses have their own factories.
 * Those three factories extend to the abstractBusFactory, which is a specified interface that is used
 * 
 * pro:
 * 
 * Factory methods eliminate the need to bind application-specific classes into code.
 * The code only deals with the product interfaces; therefore,
 * it can work with any user-defined concrete product classes.
 * 
 * con:
 * 
 * In Factory Method pattern, the factory used for creating the objects is bound with the client code.
 * It is difficult to use a different factory for creating objects.
 * \subsection factory Pattern I applied and not applied
 * I choose the ConcreteBusFactory Pattern. because it is way easier to write.
 * \subsection UML
 * UML can be found in the project/docs folder
 * \image html i3_UML.png "UML" 
 * 
 * 
 * \section  Designing and Implementing the Observer Pattern
 * I write a Observer pattern for the simulation, which is a software 
 * design pattern in which an object called the subject. I also write 
 * a ISubject, which maintains a list of bus data.
 * 
 * \image html Observer_UML.png
 * 
 * 
 * As shown by diagim above, I added new classes and new methods to UML. 
 * The advantage of using the observer pattern is that you can notify 
 * a group of related bus objects that the relevant data has changed,
 * which does not require the data server to have any prior knowledge
 * of its clients (objects). Internally, the client only provides the 
 * above subscription function to dynamically add or remove itself 
 * based on the notification. Whenever new data arrives and is notified, 
 * the data is sent. The observer pattern optimizes the interaction 
 * between the object and the server.
 * 
 * \subsection Discussion Dicussion of 2 alternate Decorator Pattern
 * 1. Decorator Architectures -Version1- I used!
 * 
 *      This version put Decorate color and intensity together in the BusDecorator. and the IBus
 * act like a connecter for the IObservable , The Bus class and the BusDecorator. Both Intensity
 * and color implemented in BusDecorator.
 *   1. Pros:
 *     It is somehow similar to the pattern that I used, except it use a Decorates Color
 * and Intensity in the same class. it kind of single-responsibility principle , almost all
 * class has their own responsibility. It also has a IBus interface that is functional for
 * communicate between clent, Bus and IObserver. It follow the open/closed principle Open
 * closed principle  it open for extension and the BusDecorator has extended class that contains
 * different methods. from the angle of cohesion and coupling, it is well organized and closely
 * related.
 *   2. Cons:
 *     This Decorate pattern is not too specific, it put the color and the intensity in the same class
 * which violate the "a class should only have a single responsibility" and it is not fulfill the
 * interface segregation principle it is not "many client-specific interfaces are better than
 * one general-purpose interface"
 * 
 * 2.Decorator Architectures - Version2 -
 *   1. Pros:
 * every class should have a single responsibility or single job. The BusColorDecorator class control the
 * color of the Bus based on the number of people on the bus. and the BusIntensityDecorator
 * control the intensity of the color. 
 *  they both open for extension/closed for modification. And the BusDecorator are able to be extend
 *  as the BusIntensityDecorator and BusColorDecorator. Its follow the cohesion rule and every classes
 * is arranged and connected in order. The design is closed to change but open to extension. The
 * IObservable class include the bus data and the IBus is a interface that make a connection between
 * the IObservable and the Bus Decorator.
 *   2. Cons:
 *     The disadvantage is that need two seperat Decorator for the bus Decorator, one for the Bus indensity,
 * and one for the bus color. In a word, it is not so simple enough . Like simple sytems composed of simple
 * components will work the best, it is not the simplest one.
 * 
 * 2. Decorator Architectures -Version3-
 * 
 *      This is the most straight way, BusWithColorNIntensity is act as a Decorator that contain the
 * color and intensity Decorate in it. And it dirctly connected to the Bus class. The bus class then
 * call the IObserver to notify the server. this method is straghtforward and no interface and not too
 * many branches.
 *   1. Pros:
 *     It is super simple and everthing in one class named BusWithColorNIntensity, which include
 * the color and intensity Decorator and it actually works, I can save some time to wrtie
 * donze of different files that can be write in a single file. this pattern does the job of cohesion
 * and coupling in somehow.
 *   2. Cons:
 *     It not follow the Single-responsibility principle, the class have multiply responsibility
 *  and it is also closed for extension, which is not effective not enough. In addition, it is Open
 * to change and modification because everything is in one class so that it can be easiily changed.
 *
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
#endif  // SRC_MAINPAGE_H_
