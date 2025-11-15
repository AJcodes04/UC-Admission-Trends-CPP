# UC-Admission-Trends-CPP

A C++ application for analyzing and visualizing UC (University of California) admission trends using data from 2012-2023 across all UC campuses.

## Requirements

- C++17 compatible compiler (GCC or Clang)
- CMake 3.10 or higher
- Matplot++ (automatically installed via Docker or manually)

### Docker 

Build the Docker image:
```bash
docker build -t uctrends .
```

Run the container:
```bash
docker run uctrends
```

2. Install Matplot++:
```bash
git clone --depth=1 https://github.com/alandefreitas/matplotplusplus.git /tmp/matplotplusplus
cd /tmp/matplotplusplus
mkdir build && cd build
cmake .. -DBUILD_EXAMPLES=OFF -DBUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/usr/local
make -j$(nproc)
sudo make install
sudo ldconfig
```

3. Build the project:
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

4. Run:
```bash
./build/UC_Addmission_Trends
```

## Data

CSV files containing admission data for all UC campuses are located in `data/csv_exports/`. Data spans from 2012 to 2023 for campuses including UCB, UCD, UCI, UCLA, UCM, UCR, UCSB, UCSC, and UCSD.
