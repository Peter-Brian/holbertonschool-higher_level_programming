-- script that lists all Comedy shows in the database hbtn_0d_tvshows
-- table contains only one record where name = Comedy (but the id can be different)
SELECT sh.title FROM tv_shows AS sh JOIN tv_show_genres AS shgr ON sh.id=shgr.show_id
JOIN tv_genres AS gr ON shgr.genre_id=gr.id
WHERE gr.name = "Comedy" ORDER BY sh.title ASC;
