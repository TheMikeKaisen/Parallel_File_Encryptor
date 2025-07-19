# Parallel File Encryptor

A high-performance C++-based file encryption/decryption system designed with modular architecture and prepared for parallel processing optimization. This project demonstrates advanced software engineering concepts including task queue management, file I/O operations, and clean separation of concerns.

## Key Features

**Core Functionality**

- **Batch File Processing**: Recursively encrypts/decrypts all files within a specified directory
- **Caesar Cipher Implementation**: Utilizes a configurable key-based character shifting encryption algorithm
- **Task Queue Management**: Implements a sophisticated task queue system using unique pointers for memory safety
- **Binary File Support**: Handles all file types through binary I/O operations

**Technical Highlights**

- **Memory-Safe Design**: Leverages smart pointers (unique_ptr) for automatic memory management
- **Modular Architecture**: Clean separation between file handling, encryption logic, and process management
- **Environment Configuration**: External configuration management through .env files
- **Comprehensive Error Handling**: Robust filesystem error management and file validation

## Technical Stack

| **Component** | **Technology** | **Purpose** |
| --- | --- | --- |
| **Core Language** | C++17 | Main implementation |
| **Compiler** | Clang++ | Build system |
| **Build Tool** | Makefile | Build automation |
| **File System** | std::filesystem | Directory traversal |
| **Memory Management** | Smart Pointers | Safe memory handling |

## 📁 Project Architecture

`textParallel_File_Encryptor/
├── src/app/
│   ├── encryptDecrypt/          # Encryption/Decryption logic
│   │   ├── Cryption.cpp         # Core encryption implementation
│   │   ├── Cryption.hpp         # Encryption interface
│   │   └── CryptionMain.cpp     # Standalone encryption tester
│   ├── fileHandling/            # File I/O operations
│   │   ├── IO.cpp               # File stream management
│   │   ├── IO.hpp               # File I/O interface
│   │   └── ReadEnv.cpp          # Environment variable reader
│   └── processes/               # Task management system
│       ├── ProcessManagement.cpp # Task queue implementation
│       ├── ProcessManagement.hpp # Process management interface
│       └── Task.hpp             # Task serialization/deserialization
├── test/                        # Test files and data
│   └── test1.txt               # Sample test file
├── .env                        # Configuration (encryption key)
├── Makefile                    # Build configuration
└── main.cpp                    # Application entry point`

## Quick Start

## Prerequisites

- C++17 compatible compiler (Clang++/G++)
- Make build system
- Unix-like operating system (Linux/macOS)

## Installation & Build

`bash*# Clone the repository*
git clone https://github.com/TheMikeKaisen/Parallel_File_Encryptor.git
cd Parallel_File_Encryptor

*# Build the main application*
make encrypt_decrypt

*# Build the standalone encryption tester*
make cryption

*# Build both targets*
make all`

## Usage

**Main Application:**

`bash*# Run the interactive file encryptor*
./encrypt_decrypt

*# Follow the prompts:# 1. Enter directory path (e.g., ./test)# 2. Choose action: "encrypt" or "decrypt"*`

**Standalone Testing:**

`bash*# Test encryption functionality directly*
./cryption "path/to/file.txt,ENCRYPT"
./cryption "path/to/file.txt,DECRYPT"`

## Configuration

- Edit **`.env`** file to modify the encryption key (default: 51678)
- Ensure proper file permissions for target directories

## Implementation Details

## Encryption Algorithm

- **Method**: Modified Caesar Cipher with configurable key
- **Operation**: Character-by-character transformation using modular arithmetic
- **Formula**:
    - Encrypt: **`(character + key) % 256`**
    - Decrypt: **`(character - key + 256) % 256`**

## Task Management

- **Queue-based Processing**: FIFO task execution using STL queue
- **Memory Safety**: Unique pointer ownership transfer prevents memory leaks
- **Serialization**: Tasks can be serialized/deserialized for future distributed processing

## File I/O Strategy

- **Binary Mode**: Handles all file types uniformly
- **Stream Management**: RAII-compliant file stream handling
- **Error Recovery**: Comprehensive error checking and reporting

## Future Roadmap

## Phase 1: Parallel Processing (In Development)

- **Multi-threading Implementation**: Worker thread pool for concurrent file processing
- **Thread-safe Queue**: Implementation of concurrent queue with proper synchronization
- **Performance Optimization**: Benchmark-driven optimization for large file sets

## Phase 2: Process Management

- **Child Process Integration**: Fork-based process management for system-level parallelism
- **Inter-process Communication**: Shared memory or message passing between processes
- **Load Balancing**: Dynamic work distribution across available processes

## Phase 3: Advanced Features

- **Multiple Encryption Algorithms**: AES, RSA integration
- **Progress Tracking**: Real-time processing status and progress bars
- **Configuration Management**: Advanced configuration file support
- **Cross-platform Support**: Windows compatibility layer

## Development Guidelines

## Code Style

- Modern C++17 features and best practices
- RAII for resource management
- Clear separation of concerns
- Comprehensive error handling

## Testing Strategy

- Unit tests for individual components
- Integration tests for end-to-end workflows
- Performance benchmarks for optimization validation

## Build System

`bash*# Development build with debug symbols*
make CXXFLAGS="-std=c++17 -g -Wall"

*# Clean build artifacts*
make clean

*# Rebuild everything*
make clean all`

## 📊 Performance Characteristics

- **Memory Efficiency**: Smart pointer usage prevents memory leaks
- **Scalability**: Queue-based design prepared for parallel scaling
- **File Size Handling**: Efficient for both small and large file processing
- **Error Resilience**: Continues processing despite individual file failures
