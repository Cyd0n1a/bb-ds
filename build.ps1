docker.exe run --rm -v C:/Users/William/Documents/Nintendo-DS-Development:/work -it --entrypoint bash `
skylyrac/blocksds:dev-latest -c "cd /work/nitro-engine && make -f Makefile.blocksds && make -f Makefile.blocksds NE_DEBUG=1 && make -f Makefile.blocksds install && cd /work/nds_nflib && make -f Makefile.blocksds install && cd /work/projects/breaking-bad-ds && make"