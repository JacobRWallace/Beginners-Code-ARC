require("dotenv").config();

const { IgApiClient } = require('instagram-private-api');
const { get } = require('request-promise');
const CronJob = require("cron").CronJob;

const postToInsta = async () => {
    const ig = new IgApiClient();
    ig.state.generateDevice(process.env.IG_USERNAME);
    await ig.account.login(process.env.IG_USERNAME, process.env.IG_PASSWORD);

    // Download the image into a buffer and ready for upload
    const imageBuffer = await get({
        url: 'https://cdn.discordapp.com/attachments/1263766595876950036/1303816979265749063/egg.jpg?ex=672d21af&is=672bd02f&hm=6ccfcb889b9ac34271c3aeca39c8522cbefbda5aca76f1222b6958f390d22ea6&',
        encoding: null, 
    });

    // Post our image to Instagram
    await ig.publish.photo({
        file: imageBuffer,
        caption: 'Really nice photo from the internet!',
    });
}

const cronInsta = new CronJob("30 * * * * *", async () => {
    postToInsta();
});

cronInsta.start();