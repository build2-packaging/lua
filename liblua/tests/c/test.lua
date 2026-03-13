function test()
  assert(accumulate(1) == 1);
  assert(accumulate(1, 2) == 3);
  assert(accumulate(1, 2, 3) == 6);
  assert(accumulate(6, 5, 4) == 15);
end
