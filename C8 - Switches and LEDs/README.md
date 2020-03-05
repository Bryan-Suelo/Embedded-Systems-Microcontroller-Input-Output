# Switches and LEDs

## Switches
Allows the human to input binary information into the computer. Typically we define the asserted state, or logic true, when the switch is pressed.
The switches are shown as little open circles. The connections have a resistance very close to 0Ω when the switch is pressed and have an almost infinite resistance when the switch is not pressed.

To convert the infinite/zero resistance into a digital signal, we can use a pull-down resistor to ground or a pull-up resistor to +3.3V.

**Positive logic** - With a pull-down resistor, the digital signal will be **low** if the switch is **not pressed** and **high** if the switch is **pressed**. 
The asserted state is a **logic high**.

**Negative logic** - With a pull-up resistor, the digital signal will be **high** if the switch is **not pressed** and **low** if the switch is **pressed**.
The asserted state is a **logic low**.

![](Images/switchInterface.jpg)