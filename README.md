<div align="center"> <h3> Student in Postgres 👨🏻‍💻 </h3> </div>

<br/>

<div align="center">
  <a href="https://open.vscode.dev/mohammadzainabbas/student-in-postgres" target="_blank"> 
    <img src="https://open.vscode.dev/badges/open-in-vscode.svg"/>
  </a>
</div>

---

### Table of contents

- [Basic](#basic)
- [Build](#build)
- [Install](#install)
- [Usage](#usage)

<a id="basic" />

#### Basic

In order to develop your base type in postgres, write:

1. Source code in `.c` file(s)
2. Define sql type and functions in `.sql` file.
3. Add control information of your extension in `.control` file

<a id="build" />

#### Build

After writing your source code, sql functions and control information, you need to first build your source code. Run the following:

```bash
make
```

> Note: If you get an error about `pg_config`, it's because `make` wasn't able to find the `pg_config` binary in your path. You can add it via the below mentioned command:

```bash
echo 'export PATH="/usr/local/pgsql/bin:$PATH"' >> ~/.bashrc && source ~/.bashrc
```

> Note: If you have installed postgres somewhere else, replace `/usr/local/pgsql/bin/` to the installation location of your postgres. 

<a id="install" />

#### Install

Installing an extension is pretty straightforward, just run the below mentioned command:

```bash
make install
```

And Voila! your extension is installed !!!

<a id="usage" />

#### Usage

In order to use your extension, create a database (in case you don't have it already) via `createdb <database-name>`:

```bash
createdb test
```

Now, connect to this database by:

```bash
psql test
```

To use your newly created extension, run:

```sql
create extension student;
```

This will dynamically load your extension.

And now, you can use it

```sql
select student '( "Mohammad" , 26 , 3.5 )';
```

Now, you can create a table with your extension:

```sql
create table demo (id int, stud student);
```

and to insert into the table,

```sql
insert into demo values (1, '( "Mohammad" , 26 , 3.5 )');
```
