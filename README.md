# UC-Admission-Trends-CPP

A C++ application for analyzing and visualizing UC (University of California) admission trends using data from 2012-2023 across all UC campuses.

## Requirements

- Docker

## Setup

Clone the repository:
```bash
git clone https://github.com/AJcodes04/UC-Admission-Trends-CPP.git
cd UC-Admission-Trends-CPP
```

Build the Docker image (Docker automatically handles all dependencies including Matplot++):
```bash
docker build -t uctrends .
```

Run the container:
```bash
docker run uctrends
```

## Project Structure

```
.
├── src/              # Source files
├── include/          # Header files
├── data/             # CSV data files (UC campuses 2012-2023)
├── CMakeLists.txt    # CMake build configuration
└── Dockerfile        # Docker build configuration
```

## Data

CSV files containing admission data for all UC campuses are located in `data/csv_exports/`. Data spans from 2012 to 2023 for campuses including UCB, UCD, UCI, UCLA, UCM, UCR, UCSB, UCSC, and UCSD.
