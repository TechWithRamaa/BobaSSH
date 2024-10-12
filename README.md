## BoBo SSH
* BoBo SSH is a command-line utility designed to connect to a remote server via a custom protocol (similar to SSH). It allows users to authenticate, execute commands remotely, and manage their server instances. BoBo Client is lightweight and simple to use, designed for environments where secure communication with remote servers is necessary

### Key Features
- **Remote Command Execution**: Execute commands on a remote server and receive the output on the client side
- **Authentication**: BoBo Client provides a simple authentication mechanism, sending usernames and passwords to ensure secure access
- **Disconnect Command**: Allows users to gracefully disconnect from the server using a specific command
- **Cross-Platform**: This client can be used on both Linux and Windows platforms
### Tech Stack
- **C++**: Core logic for handling socket programming, client-server interactions, and command execution
- **Sockets API**: Enables communication between the client and the server over TCP/IP
- **Windows/Linux Support**:  The client can be compiled and run on both Windows and Linux systems

### Getting Started

To get started with this project, follow these general steps:

1. **Clone the Repository**
   ```bash
   git clone https://github.com/TechWithRamaa/BobaSSH.git
   cd BobaSSH
   ```

2. **Build the Project**
    This project uses CMake for building. 
   ```bash
   cd BobaSSH
   mkdir build && cd build
   cmake ..
   make
   ```

3. **Run a Server**
   ```bash
   ./bin/BobaSSH
   ```

### Contributions
* Contributions are welcome! If you have an idea for a new feature implementation or improvements to existing projects, feel free to fork the repository and submit a pull request

### License
* This project is licensed under the MIT License - see the LICENSE file for details

### Acknowledgments
* Started this mini project while learning Socket Progamming as part of a course
* Check out the course here: [Advanced C++ with Networking Course](https://register.educosys.com/new-courses)
* Special shout-out to **Educosys**[🔗](https://www.educosys.com/) for meticulously curating this course and skillfully teaching concepts from the ground up

