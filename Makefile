f078m: f078m.c run.c util.c
	gcc -w -g -O2 $^ -o $@

.PHONY: clean
clean:
	rm -rf *~ f078m

test: f078m step_1 step_2 step_3 step_4 step_5 step_6 step_7 step_8 step_9 step_10

step_1:
	@echo "Testing step_1"; \
	./f078m sample_input/step1 | diff -Naur sample_output/step1 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_2:
	@echo "Testing step_2"; \
	./f078m sample_input/step2 | diff -Naur sample_output/step2 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_3:
	@echo "Testing step_3"; \
	./f078m sample_input/step3 | diff -Naur sample_output/step3 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_4:
	@echo "Testing step_4"; \
	./f078m sample_input/step4 | diff -Naur sample_output/step4 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_5:
	@echo "Testing step_5"; \
	./f078m sample_input/step5 | diff -Naur sample_output/step5 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_6:
	@echo "Testing step_6"; \
	./f078m sample_input/step6 | diff -Naur sample_output/step6 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_7:
	@echo "Testing step_7"; \
	./f078m sample_input/step7 | diff -Naur sample_output/step7 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_8:
	@echo "Testing step_8"; \
	./f078m sample_input/step8 | diff -Naur sample_output/step8 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_9:
	@echo "Testing step_9"; \
	./f078m -np -b sample_input/step9 | diff -Naur sample_output/step9 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi

step_10:
	@echo "Testing step_10"; \
	./f078m -np -w sample_input/step10 | diff -Naur sample_output/step10 - ;\
	if [ $$? -eq 0 ]; then echo "\tTest seems correct\n"; else echo "\tResults not identical, check the diff output\n"; fi
