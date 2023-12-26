# Object-Oriented Analysis (OOA) for Circuit Simulator

## 1. Overview

The Circuit Simulator is designed to model and simulate simple electric
circuits. The primary focus is on creating a framework that can simulate the
behavior of basic electronic components like resistors, capacitors, and a
battery over time.

## 2. Key Functional Requirements

- **Component Simulation**: Ability to simulate basic electronic components
  (resistors, capacitors, battery).
- **Circuit Construction**: Users should be able to build circuits by connecting
  different components.
- **Time-Step Simulation**: The simulation advances in time steps, affecting the
  charge and voltage across components.
- **Command Line Interface**: Accept simulation parameters (number of
  iterations, time step, etc.) via command line arguments.
- **Output Display**: Display the results of the simulation in a tabulated
  format.

## 3. Main Entities

### 3.1 Component

- **Attributes**: Name, connection points (terminals).
- **Behaviors**: Update state based on simulation step, calculate voltage and
  current.
- **Subclasses**: Resistor, Capacitor, Battery.

### 3.2 Circuit

- **Attributes**: List of components, connection points.
- **Behaviors**: Build circuit by connecting components, run simulation.

### 3.3 Simulator

- **Attributes**: Time step, number of iterations.
- **Behaviors**: Execute simulation steps, output results.

### 3.4 ConnectionPoint

- **Attributes**: Voltage level, connected components.
- **Behaviors**: Aggregate components sharing the same connection point.

## 4. Relationships

- **Circuit-Component**: Aggregation (Circuit contains multiple Components).
- **Component-ConnectionPoint**: Association (Components are connected via
  ConnectionPoints).

## 5. Interaction Scenarios

- **Building a Circuit**: Users instantiate Components and define their
  connections to form a Circuit.
- **Running a Simulation**: The Simulator takes a Circuit and iterates over time
  steps, during which Components update their states.
- **Outputting Results**: After completing the simulation, the results (voltage,
  current) are displayed.

## 6. User Interface

- **CLI Input**: Accepts simulation parameters and component specifications via
  command line arguments.
- **Output Display**: Outputs the simulation results in a structured format.

## 7. Constraints and Assumptions

- The simulation assumes idealized behavior for components.
- The system is limited to passive DC circuits with resistors, capacitors, and a
  single battery.
- Real-time simulation and complex circuit behaviors (like alternating current)
  are not supported.
