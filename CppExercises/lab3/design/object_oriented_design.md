# Object-Oriented Design (OOD) for Circuit Simulator

## 1. Class Diagram

This section outlines the main classes and their relationships.

### 1.1 Component (Abstract Class)

- **Attributes**:
  - `name`: string
  - `terminals`: vector<ConnectionPoint*>
- **Methods**:
  - `virtual void update(double timestep) = 0`: Updates the state of the
    component for each time step.
  - `virtual double getCurrent() const = 0`: Returns the current through the
    component.
  - `virtual double getVoltage() const = 0`: Returns the voltage across the
    component.

### 1.2 Resistor : public Component

- **Attributes**:
  - `resistance`: double
- **Methods**:
  - `void update(double timestep) override`: Implements resistance behavior in
    the circuit.

### 1.3 Capacitor : public Component

- **Attributes**:
  - `capacitance`: double
  - `charge`: double
- **Methods**:
  - `void update(double timestep) override`: Implements capacitor behavior in
    the circuit.

### 1.4 Battery : public Component

- **Attributes**:
  - `voltage`: double
- **Methods**:
  - `void update(double timestep) override`: Provides a constant voltage source.

### 1.5 Circuit

- **Attributes**:
  - `components`: vector<Component*>
  - `connectionPoints`: vector<ConnectionPoint>
- **Methods**:
  - `void addComponent(Component* component)`: Adds a component to the circuit.
  - `void connect(Component* a, Component* b)`: Connects two components in the
    circuit.

### 1.6 ConnectionPoint

- **Attributes**:
  - `voltage`: double
  - `connectedComponents`: vector<Component*>
- **Methods**: 
  - `void calculateVoltage()`: Calculates the voltage at this connection point.

### 1.7 Simulator

- **Attributes**:
  - `circuit`: Circuit
  - `timeStep`: double
  - `iterations`: int
- **Methods**:
  - `void runSimulation()`: Runs the simulation for the specified number of
    iterations and time steps.
  - `void displayResults()`: Outputs the results of the simulation.

## 2. Design Patterns and Principles

### 2.1 Composite Pattern

- **Use Case**: The `Circuit` class acts as a composite of `Component` objects.
  This allows the circuit to be treated as a single entity while containing
  multiple components.

### 2.2 Strategy Pattern

- **Use Case**: Different behaviors of components (resistors, capacitors,
  batteries) are encapsulated using the `Component` interface. This allows the
  behavior of these components to be varied independently.

### 2.3 Singleton Pattern

- **Use Case**: The `Simulator` class can be designed as a singleton if only one
  instance is required throughout the application's lifecycle.

## 3. User Interface Design

The Simulator will use a Command-Line Interface (CLI) for input and output:

- **Input**: Accept simulation parameters and commands to build the circuit.

- **Output**: Display the simulation results in a structured format.

## 4. Error Handling and Validation

- **Error Handling**: Appropriate error handling mechanisms should be in place
  for invalid component values, incorrect circuit connections, and runtime
  exceptions.
- **Validation**: Input validation for command line arguments and simulation
  parameters.

## 5. Performance Considerations

- **Efficiency**: Optimize the update methods of components for efficient
  simulation.
- **Scalability**: Ensure the design supports circuits with a large number of
  components.

## 6. Future Enhancements

- **Extensibility**: Design classes with extensibility in mind, to easily add
  new types of components or features.
