Example of c++ project, which is build and run inside docker container.

---

Build & run in docker
---

Prerequisites: (1) [docker](https://www.docker.com/), (2) unix shell (e.g. bash).

```
git clone https://github.com/artin-phares/cpp-docker-example
cd cpp-docker-example

./scripts/build.sh          # build inside docker container
./scripts/build-and-run.sh  # build inside docker container and run it
```

Run prebuild docker
---

Prerequisites: (1) [docker](https://www.docker.com/).

```
# download image from docker hub and run it (set port and folder path to save database in)
docker run -di \
    -p <port>:8080 \
    --mount type=bind,src=<database folder path>,dst=/opt/project/build/bin/data/ \
    artinphares/project-example
```

Notes:  
Database folder path should be (1) absolute, (2) exist, (3) windows format: "/d/my/folder/".
