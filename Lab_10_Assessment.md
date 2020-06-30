### Assessment for Lab 10

#### Total score: _95.0_ / _100_

Run on March 03, 14:57:02 PM.


### Necessary Files and Structure

+  _10_ / _10_ : Pass: Check that directory "labs" exists.

+  _10_ / _10_ : Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+  _10_ / _10_ : Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		018273a7483d4ca011d19877fb032d705e123860	refs/heads/devel

		f442e2a771a7bb85f0f720f2c0ac9d44afb7d160	refs/heads/fix/01-compilation-errors

		4d918bd53d2be95eafc931f005b1fb5e10ea4cd0	refs/heads/master



+  _5.0_ / _10_ : Pass: Checking for the correct number of branches

Insufficient branches found (found=1, required=2):

fix/01-compilation-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history


		[Qi Mao] 2020-03-02 (origin/fix/01-compilation-errors, fix/01-compilation-errors) fix(files): fix #1 <short description of commit> - Multiple lines of description
- Lists all the important elements that have been changed
- etc.


		[Qi Mao] 2020-03-02 fix(files): fix #1 <short description of commit> - Multiple lines of description
- Lists all the important elements that have been changed
- etc.


		[Qi Mao] 2020-03-02 add src 

		[Qi Mao] 2020-03-02 delete src 



		[Qi Mao] 2020-03-02 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-maoxx241 

		[Qi Mao] 2020-03-02 add(lab09): Adding lab09 deliverables 

		[Qi Mao] 2020-03-02 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream 
























		[Qi Mao] 2020-02-28 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream 













		[Qi Mao] 2020-02-24 add(lab08): Adding lab08 deliverables 2 

		[Qi Mao] 2020-02-24 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-maoxx241 

		[Qi Mao] 2020-02-24 add(lab08): Adding lab08 deliverables 








		[Qi Mao] 2020-02-24 add(lab08): Adding lab08 deliverables 

		[Qi Mao] 2020-02-24 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-maoxx241 

		[Qi Mao] 2020-02-24 add(lab08): Adding lab08 deliverables 



		[Qi Mao] 2020-02-24 add(lab07): Adding lab08 deliverables 


		[Qi Mao] 2020-02-24 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream 





























































































+  _5_ / _5_ : Pass: Check git commit history
Sufficient commits (found=22,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 2)

[CLOSED issue #2] :  Devel ↑

[CLOSED issue #1] :  Fix/01 compilation errors ↑





+  _10.0_ / _10_ : Pass: Run ghi for total number of issues in Github repo (Found: 2, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #2] :  Devel ↑

[CLOSED issue #1] :  Fix/01 compilation errors ↑

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+  _10_ / _10_ : Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+  _5_ / _5_ : Pass: Check that file "makefile" exists.

+  _30_ / _30_ : Pass: Check that make compiles.



#### Total score: _95.0_ / _100_

