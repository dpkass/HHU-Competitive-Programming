
#define timestart clock_t begin = clock()
#define timeend \
  clock_t end = clock(); \
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC; \
  print("took " << elapsed_secs << "sec")
